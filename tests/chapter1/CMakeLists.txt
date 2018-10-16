add_executable(TestTriangle test_triangle.cpp)
target_link_libraries(TestTriangle Triangle gtest_main)

add_executable(TestLottery test_lottery.cpp)
target_link_libraries(TestLottery Lottery gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)
gtest_discover_tests(TestTriangle)
gtest_discover_tests(TestLottery)