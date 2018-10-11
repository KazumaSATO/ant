add_executable(TestSample1 test_sample1.cpp)
target_link_libraries(TestSample1 Sample1 gtest_main)
include_directories(${PROJECT_SOURCE_DIR}/src)

include(GoogleTest)
# gtest_add_tests(TARGET TestSample1)
gtest_discover_tests(TestSample1)