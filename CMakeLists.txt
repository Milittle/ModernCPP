cmake_minimum_required(VERSION 3.21)
project(moderntest C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

include(FindFolly)
include(FindGlog)
include(FindRocksdb)

add_subdirectory(rocksdbexamples)

add_executable(moderntest main.cpp)
target_link_libraries(moderntest ${Folly_LIBRARY} ${Glog_LIBRARY})
