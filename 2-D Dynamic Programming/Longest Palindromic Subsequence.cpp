//
// Created by esraa on 8/8/2025.
//
#include <chrono>
#include <iostream>
#include <string.h>
using namespace std;

int LPS(string &str, int fstStr, int secStr, vector<vector<int>> &dp) {
    if (fstStr >= secStr) return fstStr == secStr;

    int &ret = dp[fstStr][secStr];
    if (~ret) return ret;

    if (str[fstStr] == str[secStr]) ret = 2 + LPS(str, fstStr+1, secStr-1, dp); // move both pointers
    else {// move the first or the second pointer and get the max
        int moveFirst = LPS(str, fstStr + 1, secStr, dp);
        int moveSecond = LPS(str, fstStr, secStr - 1, dp);
        ret = max(moveFirst, moveSecond);
    }

    return ret;
}

int longestPalindromeSubseq(string s) {
    const int N = s.size();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return LPS(s, 0, N-1, dp);
}

int main(){
    string s = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";

    cout<<longestPalindromeSubseq(s)<<endl;
}