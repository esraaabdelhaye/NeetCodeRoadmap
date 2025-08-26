//
// Created by esraa on 8/11/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int maxHeightIdx = 0, n = height.size();
    bool stopMovingRight = false, stopMovingLeft = false;
    for (int i=0; i<n; i++) if (height[i]>=height[maxHeightIdx]) maxHeightIdx = i;
    int left = 0, right = n-1, leftWaterVol = 0, rightWaterVol = 0, totalVol = 0, leftWall = 0, rightWall = 0;

    while (!stopMovingLeft || !stopMovingRight) {
        leftWall = max(leftWall, height[left]);
        rightWall = max(rightWall, height[right]);

        if (right == maxHeightIdx) stopMovingRight = true;
        if (left == maxHeightIdx) stopMovingLeft = true;

        right--;
        left++;

        if (!stopMovingLeft) {
            if (height[left] >= leftWall) {
                totalVol += leftWaterVol;
                leftWaterVol = 0;
            }else leftWaterVol += leftWall-height[left];
        }

        if (!stopMovingRight) {
            if (height[right] >= rightWall) {
                totalVol += rightWaterVol;
                rightWaterVol = 0;
            }else rightWaterVol += rightWall - height[right];
        }
    }
    return totalVol;
}

int main() {
    vector<int> heights = {4,2,3};
    cout<<trap(heights)<<endl;
}
