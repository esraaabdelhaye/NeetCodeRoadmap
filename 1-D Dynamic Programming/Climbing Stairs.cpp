//
// Created by esraa on 8/29/2025.
//
#include <iostream>
#include <vector>
using namespace std;


int rec(int curr, int top, vector<int> &dp) {
    if (curr==top) return 1;
    if (curr > top) return 0;

    int &ret = dp[curr];
    if (~ret) return ret;

    ret = rec(curr+1, top, dp) + rec(curr+2, top, dp);
    return ret;
}

int climbStairs(int n) {
    vector<int> dp(100, -1);
    return rec(0, n, dp);
}

int main() {
    int n = 2;
    cout<<climbStairs(n)<<endl;

}