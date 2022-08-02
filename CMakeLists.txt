cmake_minimum_required(VERSION 3.20)
project(Networking_server)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        headers/CLIENT.h)

set(SOURCE_FILES
        main.cpp src/CLIENT.cpp)


include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(Networking ${SOURCE_FILES} ${HEADER_FILES})