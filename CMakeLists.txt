cmake_minimum_required(VERSION 3.15)
project(TDD VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/tests)

set(source 
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Dollar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Franc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Money.cpp
)

add_executable(TDD ${source})

target_include_directories(TDD PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)