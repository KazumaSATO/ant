#include <iostream>
#include <string>
#include <string.h>
#include <vector>

std::string solve_best_cow_line(int n, char s[]) {
    std::string ans;

    int head = 0;
    int tail = n-1;
    int size =0;

    while(size < n) {
        int head_peek = head;
        int tail_peek = tail;
        while(true) {
            if(head_peek == tail_peek) {
                ans.push_back(s[head]);
                return ans;
            }
            if((int) s[head_peek] > (int) s[tail_peek]) {
                ans.push_back(s[tail]);
                tail--;
                size++;
                break;
            }
            if((int) s[head_peek] < (int) s[tail_peek]) {
                ans.push_back(s[head]);
                head++;
                size++;
                break;
            }

            if((int) s[head_peek] == (int) s[tail_peek]) {
                head_peek ++;
                tail_peek--; 
            }
        }
    }
    return ans;
}
