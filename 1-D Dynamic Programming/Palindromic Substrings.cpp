//
// Created by esraa on 8/27/2025.
//
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define int long long


int countSubstrings(string s) {
    int palNum = 0;
    const int N = s.size();

    for (int i=0; i<N; i++) {
        int left = i, right = i;

        while (left>=0 && right<N && s[left] == s[right]) {
            palNum++;
            left--;
            right++;
        }

        left = i;
        right = i+1;
        while (left>=0 && right<N && s[left] == s[right]) {
            palNum++;
            left--;
            right++;
        }
    }

    return palNum;
}

signed main() {

}