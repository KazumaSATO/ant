#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "chapter2/maze.h"


TEST(MazeTest, Min) {

    std::vector<std::vector<char>> maze{
        {'#', 'S', '#' },
        {'#', '.', '#' },
        {'#', '.', '.' },
        {'#', '#', 'G' }};

    EXPECT_EQ(4, solve_maze(maze, 4, 3, 0, 1));
}


