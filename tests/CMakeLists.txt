cmake_minimum_required(VERSION 3.15)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

set(source 
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exchanger.cpp
  # Внешние тестируемые сущности 
  ${CMAKE_SOURCE_DIR}/Source/Money.cpp
  ${CMAKE_SOURCE_DIR}/Source/Bank.cpp
  ${CMAKE_SOURCE_DIR}/Source/Sum.cpp
  ${CMAKE_SOURCE_DIR}/Source/CurrencysHash.cpp
)

add_executable(Tests ${source})
target_include_directories(Tests 
  PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_SOURCE_DIR}/Include
)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(Tests)