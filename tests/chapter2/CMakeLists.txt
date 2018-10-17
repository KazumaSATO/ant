add_executable(TestPartialsum test_partialsum.cpp)
target_link_libraries(TestPartialsum Partialsum gtest_main)


include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)
gtest_discover_tests(TestPartialsum)