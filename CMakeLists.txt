cmake_minimum_required(VERSION 4.1)
project(sdl_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(sdl_project/SDL3-3.4.20)
include_directories(sdl_project/SDL3-3.4.20/include)
include_directories(sdl_project/SDL3-3.4.20/include/SDL3)

add_executable(sdl_project
        sdl_project/sdl_project.cpp
)
find_package(SDL3 CONFIG REQUIRED)


target_link_libraries(sdl_project PRIVATE SDL3::SDL3)