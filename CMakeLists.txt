cmake_minimum_required(VERSION 3.15)
project(TDD VERSION 1.0.0 LANGUAGES CXX)

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/tests)

set(source
    ${CMAKE_SOURCE_DIR}/Source/main.cpp
    ${CMAKE_SOURCE_DIR}/Source/Money.cpp
    ${CMAKE_SOURCE_DIR}/Source/Bank.cpp
    ${CMAKE_SOURCE_DIR}/Source/Sum.cpp
    ${CMAKE_SOURCE_DIR}/Source/CurrencysHash.cpp
)

add_executable(TDD ${source})

target_include_directories(TDD PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)