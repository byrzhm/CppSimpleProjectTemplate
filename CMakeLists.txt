cmake_minimum_required(VERSION 3.20)

project(demo LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)

add_executable(demo main.cpp)

target_link_libraries(demo PRIVATE fmt::fmt)
