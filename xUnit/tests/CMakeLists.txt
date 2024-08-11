cmake_minimum_required(VERSION 3.15)

set(source 
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/UnitTester.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/TestCaseTest.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/TestFunctions.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../Source/TestResult.cpp
)

add_executable(xUnit_test ${source})
target_include_directories(xUnit_test 
  PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Include
)