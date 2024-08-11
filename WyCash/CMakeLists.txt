cmake_minimum_required(VERSION 3.15)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

set(source
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Money.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Bank.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Sum.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/CurrencysHash.cpp
)

add_executable(WyCash ${source})
target_include_directories(WyCash PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)