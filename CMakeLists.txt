cmake_minimum_required(VERSION 3.5.0)
project(VitalsSimulator VERSION 0.1.0 LANGUAGES C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP true
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add this line to set the exception handling flag for MSVC
if(MSVC)
    add_compile_options(/EHsc)
endif()

add_library(
  VitalSimulatorlib
  RandomNumberGenerator.cpp
  HealthParameterStub.cpp
  Formater.cpp
)

add_executable(
  VitalSimulator
  VitalsSimulator.cpp
)

add_executable(
  test-VitalSimulator
  TestHealthParameterStub.cpp
)


target_link_libraries(
  VitalSimulator
  VitalSimulatorlib
)

target_link_libraries(
  test-VitalSimulator
  GTest::gtest_main
  VitalSimulatorlib
)

include(GoogleTest)
gtest_discover_tests(test-VitalSimulator)
