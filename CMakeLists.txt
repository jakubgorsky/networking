cmake_minimum_required(VERSION 3.20)
project(Networking)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static")

set(SERVER_HEADER_FILES
        server/server_headers/SERVER.h)

set(SERVER_SOURCE_FILES
        server/server_src/SERVER.cpp)

include_directories(server/server_headers)
include_directories(server/server_src)

set(CLIENT_HEADER_FILES
        client/client_headers/CLIENT.h)

set(CLIENT_SOURCE_FILES
        client/client_src/CLIENT.cpp)

include_directories(client/client_headers)
include_directories(client/client_src)

set(IP_VALIDATOR IP_VALIDATOR/IP_VALIDATOR.cpp IP_VALIDATOR/IP_VALIDATOR.h)

include_directories(IP_VALIDATOR)

link_libraries(ws2_32 wsock32)

add_executable(Server ${SERVER_HEADER_FILES} ${SERVER_SOURCE_FILES})
add_executable(Client ${CLIENT_HEADER_FILES} ${CLIENT_SOURCE_FILES} ${IP_VALIDATOR})