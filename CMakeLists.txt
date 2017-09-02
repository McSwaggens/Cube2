cmake_minimum_required(VERSION 2.8)
project(DXEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lGL -lGLEW -lglfw")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(DXEngine ${SOURCES})

INCLUDE(FindPkgConfig)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})
