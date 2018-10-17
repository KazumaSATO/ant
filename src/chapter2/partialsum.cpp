#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "partialsum.h"

bool solve(int index, int length, int a[], int acc, int target) {
    if(acc == target) {
        return true;
    }

    if(index >= length) {
        return false;
    }
    return solve(index+1, length, a, acc, target) || solve(index+1, length, a, acc+a[index], target);
}

std::string partialsum(int n, int a[], int k) {
    if(solve(0, n, a, 0, k)) {
        return std::string("Yes"); 
    }
    return std::string("No");
}


