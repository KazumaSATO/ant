#include <iostream>
#include <vector>
#include <queue>
#include "section_scheduling.h"

int solve_section_scheduling(int n, int s[], int t[]) {

    using Task = std::pair<int, int>;

    Task tasks[n];

    for(int i =0;i < n;i++) {
        tasks[i] = {t[i], s[i]};
    }
    sort(tasks, tasks + n);

    int count = 0;
    int time = 0;
    for(int i = 0; i<n ; i++) {
        // start -> second
        // first -> end
        if(time <= tasks[i].second) {
            count++;
            time = tasks[i].first;
        }
    }

    return count;
}