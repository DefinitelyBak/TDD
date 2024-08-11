cmake_minimum_required(VERSION 3.15)

set(source 
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exchanger.cpp
  # Внешние тестируемые сущности 
  ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Money.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Bank.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Sum.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../Source/CurrencysHash.cpp
)

add_executable(WyCash_Tests ${source})
target_include_directories(WyCash_Tests 
  PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Include
)

target_link_libraries(WyCash_Tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(WyCash_Tests)