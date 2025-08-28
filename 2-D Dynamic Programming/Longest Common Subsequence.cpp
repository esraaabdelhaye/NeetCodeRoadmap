//
// Created by esraa on 8/8/2025.
//
#include <chrono>
#include <iostream>
#include <string.h>
using namespace std;

int LPS(string str1, string str2, int fstStr, int secStr, vector<vector<int>> &dp) {
    if (fstStr == str1.size() || secStr == str2.size()) return 0;

    int &ret = dp[fstStr][secStr];
    if (~ret) return ret;

    if (str1[fstStr] == str2[secStr]) ret = 1 + LPS(str1, str2, fstStr+1, secStr+1, dp); // move both pointers
    else {// move the first or the second pointer and get the max
        int moveFirst = LPS(str1, str2, fstStr + 1, secStr, dp);
        int moveSecond = LPS(str1, str2, fstStr, secStr + 1, dp);
        ret = max(moveFirst, moveSecond);
    }

    return ret;
}

int longestCommonSubsequence(string text1, string text2) {
    const int N = 3005;

    vector<vector<int>> dp(N, vector<int>(N, -1));
    return LPS(text1, text2, 0, 0, dp);
}


int main(){
    string text1 = "abc" ,text2 = "abc";

    cout<<longestCommonSubsequence(text1,text2)<<endl;
}