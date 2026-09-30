cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/4267679b6887f349f17b01ccd70c9e3483689b25.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  memory_tests
  memory_tests.cpp
  src/MMU/memory.cpp
)
target_link_libraries(
  memory_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(memory_tests)