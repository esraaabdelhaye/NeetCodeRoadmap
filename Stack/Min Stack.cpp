//
// Created by esraa on 8/11/2025.
//
#include <iostream>
#include <vector>
using namespace std;


class MinStack {
    vector<vector<int>> st;
public:
    
    void push(int val) {
        int minVal = (st.empty())? val : min(st.back()[1], val);
        st.push_back({val,minVal});
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st.back()[0];
    }

    int getMin() {
        return st.back()[1];
    }
};