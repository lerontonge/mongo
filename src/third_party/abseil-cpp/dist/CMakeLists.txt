#
# Copyright 2017 The Abseil Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# https://github.com/google/oss-policies-info/blob/main/foundational-cxx-support-matrix.md
# As of 2024-07-01, CMake 3.16 is the minimum supported version.
cmake_minimum_required(VERSION 3.16)

# Allow the user to specify the CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif (POLICY CMP0141)

project(absl LANGUAGES CXX VERSION 20250512)
set(ABSL_SOVERSION "2505.0.0")
include(CTest)

# Output directory is correct by default for most build setups. However, when
# building Abseil as a DLL, it is important to have the DLL in the same
# directory as the executable using it. Thus, we put all executables in a single
# /bin directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# when absl is included as subproject (i.e. using add_subdirectory(abseil-cpp))
# in the source tree of a project that uses it, install rules are disabled.
if(NOT CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  option(ABSL_ENABLE_INSTALL "Enable install rule" OFF)
else()
  option(ABSL_ENABLE_INSTALL "Enable install rule" ON)
endif()

set(CMAKE_INSTALL_RPATH "$ORIGIN")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
set(CMAKE_BUILD_RPATH_USE_ORIGIN ON)

option(ABSL_PROPAGATE_CXX_STD
  "Use CMake C++ standard meta features (e.g. cxx_std_17) that propagate to targets that link to Abseil"
  ON)

option(ABSL_USE_SYSTEM_INCLUDES
  "Silence warnings in Abseil headers by marking them as SYSTEM includes"
  OFF)

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_LIST_DIR}/CMake
  ${CMAKE_CURRENT_LIST_DIR}/absl/copts
)

option(ABSL_MSVC_STATIC_RUNTIME
  "Link static runtime libraries"
  OFF)
if(ABSL_MSVC_STATIC_RUNTIME)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
include(AbseilDll)
include(AbseilHelpers)


##
## Using absl targets
##
## all public absl targets are
## exported with the absl:: prefix
##
## e.g absl::base absl::synchronization absl::strings ....
##
## DO NOT rely on the internal targets outside of the prefix


# include current path
list(APPEND ABSL_COMMON_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(ABSL_USING_CLANG ON)
else()
  set(ABSL_USING_CLANG OFF)
endif()

# find dependencies
## pthread
find_package(Threads REQUIRED)

include(CMakeDependentOption)

option(ABSL_BUILD_TESTING
  "If ON, Abseil will build all of Abseil's own tests." OFF)

option(ABSL_BUILD_TEST_HELPERS
  "If ON, Abseil will build libraries that you can use to write tests against Abseil code. This option requires that Abseil is configured to use GoogleTest."
  OFF)

option(ABSL_USE_EXTERNAL_GOOGLETEST
  "If ON, Abseil will assume that the targets for GoogleTest are already provided by the including project. This makes sense when Abseil is used with add_subdirectory." OFF)

cmake_dependent_option(ABSL_FIND_GOOGLETEST
  "If ON, Abseil will use find_package(GTest) rather than assuming that GoogleTest is already provided by the including project."
  ON
  "ABSL_USE_EXTERNAL_GOOGLETEST"
  OFF)


option(ABSL_USE_GOOGLETEST_HEAD
  "If ON, abseil will download HEAD from GoogleTest at config time." OFF)

set(ABSL_GOOGLETEST_DOWNLOAD_URL "" CACHE STRING "If set, download GoogleTest from this URL")

set(ABSL_LOCAL_GOOGLETEST_DIR "/usr/src/googletest" CACHE PATH
  "If ABSL_USE_GOOGLETEST_HEAD is OFF and ABSL_GOOGLETEST_URL is not set, specifies the directory of a local GoogleTest checkout."
  )

option(ABSL_BUILD_MONOLITHIC_SHARED_LIBS
  "Build Abseil as a single shared library (always enabled for Windows)"
  OFF
)
if(NOT BUILD_SHARED_LIBS AND ABSL_BUILD_MONOLITHIC_SHARED_LIBS)
  message(WARNING "Not building a shared library because BUILD_SHARED_LIBS is not set. Ignoring ABSL_BUILD_MONOLITHIC_SHARED_LIBS.")
endif()

if((BUILD_TESTING AND ABSL_BUILD_TESTING) OR ABSL_BUILD_TEST_HELPERS)
  if (ABSL_USE_EXTERNAL_GOOGLETEST)
    if (ABSL_FIND_GOOGLETEST)
      find_package(GTest REQUIRED)
    elseif(NOT TARGET GTest::gtest)
      if(TARGET gtest)
        # When Google Test is included directly rather than through find_package, the aliases are missing.
        add_library(GTest::gtest ALIAS gtest)
        add_library(GTest::gtest_main ALIAS gtest_main)
        add_library(GTest::gmock ALIAS gmock)
        add_library(GTest::gmock_main ALIAS gmock_main)
      else()
        message(FATAL_ERROR "ABSL_USE_EXTERNAL_GOOGLETEST is ON and ABSL_FIND_GOOGLETEST is OFF, which means that the top-level project must build the Google Test project. However, the target gtest was not found.")
      endif()
    endif()
  else()
    set(absl_gtest_build_dir ${CMAKE_BINARY_DIR}/googletest-build)
    if(ABSL_USE_GOOGLETEST_HEAD AND ABSL_GOOGLETEST_DOWNLOAD_URL)
      message(FATAL_ERROR "Do not set both ABSL_USE_GOOGLETEST_HEAD and ABSL_GOOGLETEST_DOWNLOAD_URL")
    endif()
    if(ABSL_USE_GOOGLETEST_HEAD)
      set(absl_gtest_download_url "https://github.com/google/googletest/archive/main.zip")
    elseif(ABSL_GOOGLETEST_DOWNLOAD_URL)
      set(absl_gtest_download_url ${ABSL_GOOGLETEST_DOWNLOAD_URL})
    endif()
    if(absl_gtest_download_url)
      set(absl_gtest_src_dir ${CMAKE_BINARY_DIR}/googletest-src)
    else()
      set(absl_gtest_src_dir ${ABSL_LOCAL_GOOGLETEST_DIR})
    endif()
    include(CMake/Googletest/DownloadGTest.cmake)
  endif()
endif()

add_subdirectory(absl)

if(ABSL_ENABLE_INSTALL)
  

  # install as a subdirectory only
  install(EXPORT ${PROJECT_NAME}Targets
    NAMESPACE absl::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )

  configure_package_config_file(
    CMake/abslConfig.cmake.in
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )
  install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )

  # Abseil only has a version in LTS releases.  This mechanism is accomplished
  # Abseil's internal Copybara (https://github.com/google/copybara) workflows and
  # isn't visible in the CMake buildsystem itself.
  if(absl_VERSION)
    write_basic_package_version_file(
      "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
      COMPATIBILITY ExactVersion
    )

    install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
      DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
    )
  endif()  # absl_VERSION

  # Install the headers except for "options.h" which is installed separately.
  install(DIRECTORY absl
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
      PATTERN "*.inc"
      PATTERN "*.h"
      PATTERN "options.h" EXCLUDE
      PATTERN "copts" EXCLUDE
      PATTERN "testdata" EXCLUDE
    )

  # Rewrite options.h to use the compiled ABI.
  file(READ "absl/base/options.h" ABSL_INTERNAL_OPTIONS_H_CONTENTS)

  # Handle features that require at least C++20.
  if (ABSL_INTERNAL_AT_LEAST_CXX20)
    foreach(FEATURE "ORDERING")
      string(REPLACE
      "#define ABSL_OPTION_USE_STD_${FEATURE} 2"
      "#define ABSL_OPTION_USE_STD_${FEATURE} 1"
      ABSL_INTERNAL_OPTIONS_H_PINNED
      "${ABSL_INTERNAL_OPTIONS_H_CONTENTS}")
      set(ABSL_INTERNAL_OPTIONS_H_CONTENTS "${ABSL_INTERNAL_OPTIONS_H_PINNED}")
    endforeach()
  endif()

  # Handle features that require at least C++17.
  if (ABSL_INTERNAL_AT_LEAST_CXX17)
    foreach(FEATURE "ANY" "OPTIONAL" "STRING_VIEW" "VARIANT")
      string(REPLACE
      "#define ABSL_OPTION_USE_STD_${FEATURE} 2"
      "#define ABSL_OPTION_USE_STD_${FEATURE} 1"
      ABSL_INTERNAL_OPTIONS_H_PINNED
      "${ABSL_INTERNAL_OPTIONS_H_CONTENTS}")
      set(ABSL_INTERNAL_OPTIONS_H_CONTENTS "${ABSL_INTERNAL_OPTIONS_H_PINNED}")
    endforeach()
  endif()

  # Any feature that still has the value of 2 (because it was not handled above)
  # should be set to 0.
  string(REGEX REPLACE
    "#define ABSL_OPTION_USE_STD_([^ ]*) 2"
    "#define ABSL_OPTION_USE_STD_\\1 0"
    ABSL_INTERNAL_OPTIONS_H_PINNED
    "${ABSL_INTERNAL_OPTIONS_H_CONTENTS}")

  # If the file already exists, check if it matches the new contents.
  # This avoids writing the file if it is already up-to-date when the CMake
  # generation is triggered and triggering unnecessary rebuilds.
  set(ABSL_INTERNAL_OPTIONS_H_PINNED_NEEDS_UPDATE TRUE)
  if (EXISTS "${CMAKE_BINARY_DIR}/options-pinned.h")
    file(READ "${CMAKE_BINARY_DIR}/options-pinned.h" ABSL_INTERNAL_OPTIONS_PINNED_H_CONTENTS)
    if ("${ABSL_INTERNAL_OPTIONS_H_PINNED}" STREQUAL "${ABSL_INTERNAL_OPTIONS_PINNED_H_CONTENTS}")
      set(ABSL_INTERNAL_OPTIONS_H_PINNED_NEEDS_UPDATE FALSE)
    endif()
  endif()

  # If the file needs an update, generate it.
  if (ABSL_INTERNAL_OPTIONS_H_PINNED_NEEDS_UPDATE)
    file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/options-pinned.h" CONTENT "${ABSL_INTERNAL_OPTIONS_H_PINNED}")
  endif()

  install(FILES "${CMAKE_BINARY_DIR}/options-pinned.h"
         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/absl/base
         RENAME "options.h")

endif()  # ABSL_ENABLE_INSTALL
