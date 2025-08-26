//
// Created by esraa on 8/12/2025.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void getPattern(int open, int close, int n, string &curr, vector<string> &ans) {
    cout<<"info: open = "<<open<<" close = "<<close<<" current string: "<<curr<<endl;   // for tracking function calls
    if (curr.size() == 2*n) {
        ans.push_back(curr);
        return;
    }

    if (open < n) {
        curr += "(";
        getPattern(open + 1, close, n, curr, ans);
        curr = curr.substr(0, curr.length() - 1);
    }
    if (close<open) {
        curr += ")";
        getPattern(open,close+1, n, curr, ans);
        curr = curr.substr(0, curr.length() - 1);
    }
}

vector<string> generateParenthesis(int n) {
    string curr = "";
    vector<string> ans;
    getPattern(0,0, n, curr, ans);
    return ans;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (string &s: ans) cout<<s<<endl;
}