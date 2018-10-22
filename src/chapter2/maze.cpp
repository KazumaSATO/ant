#include <iostream>
#include <vector>
#include <queue>
#include "maze.h"


class Maze {

public: 
    std::vector<std::vector<char>> maze;
    int x;
    int y;

    Maze(std::vector<std::vector<char>> maze1, int c_x, int c_y) {
        x = c_x;
        y = c_y;
        for(auto itr = maze1.begin(); itr != maze1.end(); ++itr) {
            std::vector<char> r(*itr);
            maze.push_back(r);
        }
    }

    void plot() {
        for(auto itr = maze.begin(); itr != maze.end(); ++itr) {
            for(auto it = itr->begin(); it != itr->end(); ++it) {
                std::cout << *it;
            }
            std::cout << std::endl;
        }           
        std::cout << "fin";
    }

};

int solve_maze(std::vector<std::vector<char>> maze, int n, int m, int sr, int sc) {
    std::vector<std::vector<int>> passed;

    using P = std::pair<int, int>;

    for(int i=0; i<n; i++) {
        passed.push_back(std::vector<int>(m, -1));
    }

    std::queue<P> que;

    passed[sr][sc] = 0;

    que.push({sr, sc});

    while(!que.empty()) {
        P dot = que.front();
        que.pop();
        if(maze[dot.first][dot.second] == 'G') {
            return passed[dot.first][dot.second];
        }
        // up
        int up =dot.first - 1; 
        if(0 <= up && passed[up][dot.second] == -1 && maze[up][dot.second] != '#') {
            passed[up][dot.second] = passed[dot.first][dot.second] + 1;
            que.push({up, dot.second});
        }
        int down = dot.first + 1;
        if(down < n && passed[down][dot.second] == -1 && maze[down][dot.second] != '#') {
            passed[down][dot.second] = passed[dot.first][dot.second] + 1;
            que.push({down, dot.second});
        }
        int left = dot.second - 1;
        if(0<= left && passed[dot.first][left] == -1 && maze[dot.first][left] != '#') {
            passed[dot.first][left] = passed[dot.first][dot.second] + 1;
            que.push({dot.first, left});
        }
        int right = dot.second + 1;
        if(right < m && passed[dot.first][right] == -1 && maze[dot.first][right] != '#') {
            passed[dot.first][right] = passed[dot.first][dot.second] + 1;
            que.push({dot.first, right});
        }
    }
}