add_executable(TestTriangle test_triangle.cpp)
target_link_libraries(TestTriangle Triangle gtest_main)
include_directories(${PROJECT_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(TestTriangle)