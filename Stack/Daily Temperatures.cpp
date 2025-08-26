//
// Created by esraa on 8/13/2025.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> temp_idx;
    vector<int> ans(n,0);

    for (int i=0; i<n; i++) {
        while (!temp_idx.empty() && temperatures[i] > temperatures[temp_idx.top()]) {
            int idx = temp_idx.top();
            ans[idx] = i-idx;
            temp_idx.pop();
        }
        temp_idx.push(i);
    }

    return ans;
}

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (int num: ans) cout<<num<<" ";
    cout<<endl;
}