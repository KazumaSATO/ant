#include<iostream>
#include<algorithm>
#include "saruman.h"


int solve_saruman(int n, int r, int x[]) {
    if(n ==1)
        return 1;
    int count = 0;

    int i = 1;
    int left_unmarked = 0;
    while(i<n) {
        if(x[left_unmarked] + r < x[i]) {
            std::cout << x[left_unmarked] << "+" << x[i] << std::endl;
            left_unmarked = i; 

            count++;
        }
        i++;
    }
    return count;
}
