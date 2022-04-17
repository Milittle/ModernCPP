# - Try to find Zstd includes dirs and libraries
#
# Usage of this module as follows:
#
#     find_package(Zstd)
#
# Variables used by this module, they can change the default behaviour and need
# to be set before calling find_package:
#
# Variables defined by this module:
#
#  Zlib_FOUND            System has Zstd, include and lib dirs found
#  Zlib_INCLUDE_DIR      The Zlib includes directories.
#  Zlib_LIBRARY          The Zlib library.
#  Zlib_BIN              The Zlib binary.

find_path(Zlib_INCLUDE_DIR NAMES zstd.h)
find_library(Zlib_LIBRARY NAMES libzstd.a)

if(Zlib_INCLUDE_DIR AND Zlib_LIBRARY)
    set(Zlib_FOUND TRUE)
    mark_as_advanced(
            Zlib_INCLUDE_DIR
            Zlib_LIBRARY
    )
endif()

if(NOT Zlib_FOUND)
    message(FATAL_ERROR "Zlib doesn't exist")
endif()

