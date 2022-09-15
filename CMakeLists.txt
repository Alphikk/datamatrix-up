cmake_minimum_required(VERSION 3.16)


project (datamatrix-up)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_ZeroMQ QUIET zmq)

find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS})


find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS})

set (INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

add_executable(client src/client.cpp)
target_include_directories(client PUBLIC ${INCLUDE_DIR} ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(client ${ZeroMQ_LIBRARY})

add_executable(server src/server.cpp)
target_include_directories(server PUBLIC ${INCLUDE_DIR} ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(server ${ZeroMQ_LIBRARY})
