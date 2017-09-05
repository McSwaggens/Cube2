cmake_minimum_required(VERSION 2.8)
project(Cube2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lGL -lGLEW -lglfw -lSOIL")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Cube2 ${SOURCES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME})
