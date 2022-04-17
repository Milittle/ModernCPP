# - Try to find Rocksdb includes dirs and libraries
#
# Usage of this module as follows:
#
#     find_package(Rocksdb)
#
# Variables used by this module, they can change the default behaviour and need
# to be set before calling find_package:
#
# Variables defined by this module:
#
#  Rocksdb_FOUND            System has Rocksdb, include and lib dirs found
#  Rocksdb_INCLUDE_DIR      The Rocksdb includes directories.
#  Rocksdb_LIBRARY          The Rocksdb library.

find_path(ROCKSDB_INCLUDE_DIR rocksdb/db.h
        PATHS "")
include_directories(${ROCKSDB_INCLUDE_DIR})
find_library(ROCKSDB_LIB rocksdb)
message(STATUS "finding ${ROCKSDB_LIB}")