# Generates "mongo.h" config header file containing feature flags generated by checking for the availability of certain compiler features.
# This script is invoked by the Bazel build system to generate the "mongo.h" file automatically as part of the build.
# Example usage:
# python mongo_config_header.py --compiler-path /usr/bin/gcc --compiler-args "-O2 -Wall" --output-path mongo.h
import argparse
import platform
import subprocess
import threading
import re
import sys
from typing import Dict
import textwrap

logfile_path: str = ""
loglock = threading.Lock()
def log_check(message):
    global loglock, logfile_path
    with loglock:
        with open(logfile_path, "a") as f:
            f.write(message + "\n")

def fail_with_bad_version_file(var, inputs):
    print(f"Failed to find version variable: {var} in {inputs}")
    sys.exit(1)

def generate_config_header(compiler_path, compiler_args, env_vars, logpath, additional_inputs, extra_definitions={}) -> Dict[str, str]:

    global logfile_path
    logfile_path = logpath
    log_check(f"Checking {additional_inputs[0]} for versions")

    VERSION_MAJOR = None
    VERSION_MINOR = None
    VERSION_PATCH = None
    VERSION_STRING = None

    # Read the version information from the version.cmake file
    for l in open(additional_inputs[0]):
        m = re.match(r'^set\(WT_(VERSION_[A-Z]+) (.+)\)', l)
        if m and len(m.groups()) == 2:
            if m.group(1) == "VERSION_MAJOR":
                VERSION_MAJOR = m.group(2)
            elif m.group(1) == "VERSION_MINOR":
                VERSION_MINOR = m.group(2)
            elif m.group(1) == "VERSION_PATCH":
                VERSION_PATCH = m.group(2)
            elif m.group(1) == "VERSION_STRING":
                VERSION_STRING = m.group(2)

    if VERSION_MAJOR is None:
        fail_with_bad_version_file("VERSION_MAJOR")
    if VERSION_MINOR is None:
        fail_with_bad_version_file("VERSION_MINOR")
    if VERSION_PATCH is None:
        fail_with_bad_version_file("VERSION_PATCH")
    if VERSION_STRING is None:
        fail_with_bad_version_file("VERSION_STRING")


    wiredtiger_includes = """
            #include <sys/types.h>
            #ifndef _WIN32
            #include <inttypes.h>
            #endif
            #include <stdarg.h>
            #include <stdbool.h>
            #include <stdint.h>
            #include <stdio.h>
        """
    wiredtiger_includes = textwrap.dedent(wiredtiger_includes)
    replacements = {
        '@VERSION_MAJOR@':
            VERSION_MAJOR,
        '@VERSION_MINOR@':
            VERSION_MINOR,
        '@VERSION_PATCH@':
            VERSION_PATCH,
        '@VERSION_STRING@':
            VERSION_STRING,
        '@uintmax_t_decl@':
            "",
        '@uintptr_t_decl@':
            "",
        '@off_t_decl@':
            'typedef int64_t wt_off_t;' if sys.platform == "win32" else "typedef off_t wt_off_t;",
        '@wiredtiger_includes_decl@':
            wiredtiger_includes,
    }

    return replacements
