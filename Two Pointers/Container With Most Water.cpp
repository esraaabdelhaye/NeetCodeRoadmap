//
// Created by esraa on 8/10/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0, left = 0, right = height.size()-1;
    while (left<right) {
        int currArea = (right - left) * min(height[left], height[right]);
        if (currArea > maxArea) maxArea = currArea;
        if (height[left]<height[right]) left++;
        else right--;
    }
    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<endl;
}