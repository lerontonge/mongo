// Automatically generated by ./configure 
#ifndef _CONFIG_H_
#define _CONFIG_H_
// distro
#define SOLIB_EXT ".so"
#define ARCH "aarch64"
#define CPU "generic"
#define WITHOUT_OPTIMIZATION 0
#define WITH_STRIP 0
#define ENABLE_ZLIB "try"
#define ENABLE_ZSTD "try"
#define ENABLE_SSL "try"
#define ENABLE_GSSAPI "try"
#define ENABLE_CURL "try"
#define ENABLE_DEVEL 0
#define ENABLE_VALGRIND 0
#define ENABLE_REFCNT_DEBUG 0
#define ENABLE_LZ4_EXT 1
#define ENABLE_LZ4_EXT 1
#define ENABLE_REGEX_EXT 1
#define ENABLE_C11THREADS 0
#define ENABLE_SYSLOG 1
#define MKL_APP_NAME "librdkafka"
#define MKL_APP_DESC_ONELINE "The Apache Kafka C/C++ library"
// gcc
#define WITH_GCC 1
// gxx
#define WITH_GXX 1
// install
#define WITH_INSTALL 1
// gnuar
#define HAS_GNU_AR 1
// PIC
#define HAVE_PIC 1
// gnulib
#define WITH_GNULD 1
// __atomic_32
#define HAVE_ATOMICS_32 1
// __atomic_32
#define HAVE_ATOMICS_32_ATOMIC 1
// atomic_32
#define ATOMIC_OP32(OP1,OP2,PTR,VAL) __atomic_ ## OP1 ## _ ## OP2(PTR, VAL, __ATOMIC_SEQ_CST)
// __atomic_64
#define HAVE_ATOMICS_64 1
// __atomic_64
#define HAVE_ATOMICS_64_ATOMIC 1
// atomic_64
#define ATOMIC_OP64(OP1,OP2,PTR,VAL) __atomic_ ## OP1 ## _ ## OP2(PTR, VAL, __ATOMIC_SEQ_CST)
// atomic_64
#define ATOMIC_OP(OP1,OP2,PTR,VAL) __atomic_ ## OP1 ## _ ## OP2(PTR, VAL, __ATOMIC_SEQ_CST)
// parseversion
#define RDKAFKA_VERSION_STR "2.6.0"
// parseversion
#define MKL_APP_VERSION "2.6.0"
// c11threads
#define WITH_C11THREADS 0
// libdl
#define WITH_LIBDL 1
// WITH_PLUGINS
#define WITH_PLUGINS 1
// libssl
#define WITH_SSL 1
// libcrypto
#define OPENSSL_SUPPRESS_DEPRECATED "OPENSSL_SUPPRESS_DEPRECATED"
// libsasl2
#define WITH_SASL_CYRUS 1
// libcurl
#define WITH_CURL 1
// WITH_HDRHISTOGRAM
#define WITH_HDRHISTOGRAM 1
// syslog
#define WITH_SYSLOG 1
// WITH_SNAPPY
#define WITH_SNAPPY 1
// WITH_SOCKEM
#define WITH_SOCKEM 1
// WITH_SASL_SCRAM
#define WITH_SASL_SCRAM 1
// WITH_SASL_OAUTHBEARER
#define WITH_SASL_OAUTHBEARER 1
// WITH_OAUTHBEARER_OIDC
#define WITH_OAUTHBEARER_OIDC 1
// regex
#define HAVE_REGEX 1
// rand_r
#define HAVE_RAND_R 1
// strndup
#define HAVE_STRNDUP 1
// strerror_r
#define HAVE_STRERROR_R 1
// strcasestr
#define HAVE_STRCASESTR 1
// pthread_setname_gnu
#define HAVE_PTHREAD_SETNAME_GNU 1
// python3
#define HAVE_PYTHON 1
// getrusage
#define HAVE_GETRUSAGE 1
// BUILT_WITH
#define BUILT_WITH "GCC GXX INSTALL GNULD LDS C11THREADS LIBDL PLUGINS SSL SASL_CYRUS CURL HDRHISTOGRAM SYSLOG SNAPPY SOCKEM SASL_SCRAM SASL_OAUTHBEARER OAUTHBEARER_OIDC"
#endif /* _CONFIG_H_ */
