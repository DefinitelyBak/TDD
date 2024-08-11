cmake_minimum_required(VERSION 3.15)
project(TDD VERSION 1.0.0 LANGUAGES CXX)

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/WyCash)
add_subdirectory(${CMAKE_SOURCE_DIR}/xUnit)
