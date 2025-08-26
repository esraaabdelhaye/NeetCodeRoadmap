//
// Created by esraa on 8/14/2025.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> areaStartingAt(n, 0);
    stack<int> st;

    for (int i=0; i<n; i++) {

        while (!st.empty() && heights[i] < heights[st.top()]) {
            areaStartingAt[st.top()] += heights[st.top()] * (i-st.top());
            st.pop();
        }
        if (!st.empty()) areaStartingAt[i] += heights[i] * (i-st.top()-1);
        else areaStartingAt[i] += heights[i] * (i);

        st.push(i);
    }

    while (!st.empty()) {
        areaStartingAt[st.top()] += (n-st.top()) * heights[st.top()];
        st.pop();
    }
    int maxArea = 0;
    for (int area: areaStartingAt) {
        if (area>maxArea) maxArea = area;
    }
    return maxArea;
}

int main() {
    vector<int> heights = {3,6,5,7,4,8,1,0};
    cout<<largestRectangleArea(heights)<<endl;
}