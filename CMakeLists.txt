cmake_minimum_required(VERSION 3.16)


project (datamatrix-up)

#find_package(PkgConfig REQUIRED)

set (INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

add_executable(main src/main.cpp)
target_include_directories(main PUBLIC ${INCLUDE_DIR})
#target_link_libraries(main)


