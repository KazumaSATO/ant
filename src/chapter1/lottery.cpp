#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "lottery.h"

std::string solve_lottery(int n, int m, int k[]) {
    int max_n = 50;
    int kk_size = max_n*max_n;

    int kk[kk_size];
    for(int i=0; i< n; i++) {
        for(int j=0; j< n; j++) {
            kk[i*n+j] = k[i] + k[j];
        }
    }
    std::vector<int> data(kk, kk + n*n);  
	std::sort(data.begin(),data.end());

    for(int i=0; i<n; i++) {
        for(int j=0;j<n; j++) {
             if (std::binary_search(data.begin(), data.end(), m - k[i] - k[j])) {
                 return std::string("Yes");
             }
        }
    }

    return std::string("No");
}


void asc_sort(int array[], int size) {
    std::sort(array, array+size);
}