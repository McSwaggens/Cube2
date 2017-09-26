cmake_minimum_required(VERSION 2.8)
project(Cube2)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Cube2 ${SOURCES})

if (APPLE)
message("Using Apple linker flags.")
set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -lGLEW -lglfw -lSOIL")
elseif (UNIX AND NOT APPLE)
message("Using UNIX/Linux linker flags.")
set(CMAKE_EXE_LINKER_FLAGS "-lGL -lGLEW -lglfw -lSOIL")
endif()
TARGET_LINK_LIBRARIES(${PROJECT_NAME})
