cmake_minimum_required(VERSION 3.20)
project(Networking_server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static")

set(HEADER_FILES
        server/server_headers/SERVER.h)

set(SOURCE_FILES
        server/server_src/SERVER.cpp)

link_libraries(ws2_32 wsock32)

include_directories(server/server_headers)
include_directories(server/server_src)

add_executable(Networking ${SOURCE_FILES} ${HEADER_FILES})