cmake_minimum_required(VERSION 3.10)
project(networkprogramming)


set(CMAKE_C_STANDARD 11)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
# Include OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")
# Add executable
add_executable(networkprogramming ${SOURCES})
target_link_libraries(networkprogramming ${OPENSSL_LIBRARIES})
