cmake_minimum_required(VERSION 3.28)
project(klases)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "/O1")
set(CMAKE_CXX_FLAGS_DEBUG "/O2")
set(CMAKE_CXX_FLAGS_DEBUG "/O3")

message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")


include_directories(include)


file(GLOB SOURCES "src/*.cpp")


add_executable(klases ${SOURCES})
