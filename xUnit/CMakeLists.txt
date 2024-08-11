cmake_minimum_required(VERSION 3.15)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

set(source
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/TestResult.cpp
)

add_executable(xUnit ${source})
target_include_directories(xUnit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)

