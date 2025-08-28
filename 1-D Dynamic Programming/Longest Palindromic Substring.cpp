//
// Created by esraa on 8/27/2025.
//
#include <iostream>
using namespace std;

string expandAround(string s, int left, int right) {
    const int N = s.size();
    while (left>=0 && right < N && s[left] == s[right]) {
            left--;
            right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    string res = "";
    const int N = s.size();
    if (N <= 1) return s;

    for (int i=0; i<N; i++) {
        string odd = expandAround(s,i,i);
        string even = expandAround(s, i, i+1);

        if (odd.size()>res.size()) res = odd;
        if (even.size()>res.size()) res = even;
    }
    return res;
}

int main() {
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}