add_executable(TestPartialsum test_partialsum.cpp)
target_link_libraries(TestPartialsum Partialsum gtest_main)

add_executable(TestMaze test_maze.cpp)
target_link_libraries(TestMaze Maze gtest_main)

add_executable(TestSectionScheduling test_section_scheduling.cpp)
target_link_libraries(TestSectionScheduling SectionScheduling gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)
gtest_discover_tests(TestPartialsum)
gtest_discover_tests(TestMaze)
gtest_discover_tests(TestSectionScheduling)

