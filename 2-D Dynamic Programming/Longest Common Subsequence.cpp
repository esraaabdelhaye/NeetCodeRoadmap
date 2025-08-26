//
// Created by esraa on 8/8/2025.
//
#include <chrono>
#include <iostream>
#include <string.h>
using namespace std;

int getAns(int idx1, int idx2, string &text1, string &text2, int memo[1001][1001]) {

}

int longestCommonSubsequence(string text1, string text2) {

}


// int getAns(int idx1, int idx2, string &text1, string &text2, int memo[1001][1001]) {
//     if (idx1 == text1.size() || idx2 == text2.size()) return 0;
//     if (memo[idx1][idx2]>=0) return memo[idx1][idx2];
//     if (text1[idx1] == text2[idx2]) return 1 + getAns(idx1+1, idx2 + 1, text1, text2, memo);
//
//     memo[idx1][idx2] = max(getAns(idx1 + 1, idx2, text1, text2, memo), getAns(idx1, idx2 + 1, text1, text2, memo));
//     return memo[idx1][idx2];
// }
//
// int longestCommonSubsequence(string text1, string text2) {
//     int memo[1001][1001];
//     memset(memo, -1, sizeof(memo));
//     return getAns(0, 0,text1,text2, memo);
// }

int main(){
    string text1 = "abc" ,text2 = "abc";

    cout<<longestCommonSubsequence(text1,text2)<<endl;
}