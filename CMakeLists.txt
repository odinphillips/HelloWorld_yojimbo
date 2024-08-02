cmake_minimum_required(VERSION 3.12.0)
project(HelloWorld_yojimbo)

set(CMAKE_CXX_FLAGS "-g -std=c++20")

if((NOT CMAKE_SYSTEM_NAME STREQUAL "Linux") AND (NOT CMAKE_SYSTEM_NAME STREQUAL "Windows"))
    message(FATAL_ERROR "Platform ${CMAKE_SYSTEM_NAME} is not supported!")
endif ()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_path(YOJIMBO_PATH "yojimbo-1.2.3" "/deps")
    set(YOJIMBO_ROOT "${YOJIMBO_PATH}/yojimbo-1.2.3")
    set(YOJIMBO_BIN "${YOJIMBO_PATH}/yojimbo-1.2.3/bin")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_path(YOJIMBO_PATH "yojimbo-1.2.3" "C:/msys64/deps")
    set(YOJIMBO_ROOT "${YOJIMBO_PATH}/yojimbo-1.2.3")
    set(YOJIMBO_BIN "${YOJIMBO_PATH}/yojimbo-1.2.3/bin/Debug")
endif()

find_library(YOJIMBO_LIB yojimbo ${YOJIMBO_BIN})
find_library(NETCODE_LIB netcode ${YOJIMBO_BIN})
find_library(RELIABLE_LIB reliable ${YOJIMBO_BIN})
find_library(SODIUM_BUILTIN_LIB sodium-builtin ${YOJIMBO_BIN})
find_library(TLSF_LIB tlsf ${YOJIMBO_BIN})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SODIUM_LIB "sodium")
    set(WINSOCK "")
    # NOTE: this library might be required for Windows one day
    # set(IP_HELPER "")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_library(SODIUM_LIB sodium "C:/deps/libsodium-1.0.20-stable-msvc/libsodium/x64/Debug/v143/static")
    find_library(WINSOCK WS2_32 "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um/x64")
    # find_library(IP_HELPER iphlpapi "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um/x64")
endif()

# NOTE: Change to target_link_libraries() for specific-only targets
link_libraries(
    ${YOJIMBO_LIB}
    ${NETCODE_LIB}
    ${RELIABLE_LIB}
    ${SODIUM_BUILTIN_LIB}
    # sodium
    ${SODIUM_LIB}
    ${TLSF_LIB}
    ${WINSOCK}
    # ${IP_HELPER}
)

# NOTE: Change to target_include_directories() for specific-only targets
include_directories(
    "${YOJIMBO_ROOT}/include"
    "${YOJIMBO_ROOT}/netcode"
    "${YOJIMBO_ROOT}/serialize"
    "${YOJIMBO_ROOT}/sodium"
    "${YOJIMBO_ROOT}/tlsf"
)

set(CLIENT_SRCS
    "${CMAKE_SOURCE_DIR}/src/GameAdapter.cpp"
    # "${CMAKE_SOURCE_DIR}/src/key_press.cpp"
    "${CMAKE_SOURCE_DIR}/src/GameServer.cpp"
    "${CMAKE_SOURCE_DIR}/src/GameClient.cpp"
    "${CMAKE_SOURCE_DIR}/src/main_game_client.cpp"
)

set(SERVER_SRCS
    "${CMAKE_SOURCE_DIR}/src/GameAdapter.cpp"
    "${CMAKE_SOURCE_DIR}/src/GameServer.cpp"
    "${CMAKE_SOURCE_DIR}/src/main_game_server.cpp"
)

add_executable(HelloWorld_yojimbo_client
    ${CLIENT_SRCS}
)

add_executable(HelloWorld_yojimbo_server
    ${SERVER_SRCS}
)
