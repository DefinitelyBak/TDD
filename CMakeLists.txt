cmake_minimum_required(VERSION 3.15)
project(TDD VERSION 1.0.0 LANGUAGES CXX)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/WyCash)
add_subdirectory(${CMAKE_SOURCE_DIR}/xUnit)
