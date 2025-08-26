//
// Created by esraa on 8/18/2025.
//
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int rec(int lastIdx, int currIdx, vector<int> &nums, vector<vector<int>> &dp) {

    if (currIdx >= nums.size()) return 0;

    int &ret = dp[lastIdx][currIdx];
    if (~ret) return ret;

    int pick = 0, skip = 0;
    // pick curr if nums[curr] > nums[last]
    if(nums[currIdx] > nums[lastIdx])
        pick = 1 + rec(currIdx, currIdx+1, nums,dp);

    // skip curr and continue in the sequence
    skip = rec(lastIdx, currIdx + 1, nums, dp);

    ret = max(skip , pick);
    return ret;
}

int getLIS(vector<int> &nums) {
    int n = nums.size();
    int maxLenght = 0;
    vector<int> dp(n,1);

    for (int curr=0; curr<n; curr++) {
        for (int prev=0; prev<curr; prev++) {

            if (nums[curr] > nums[prev]) {
                dp[curr] = dp[prev] + 1;
            }

        }

        maxLenght = max(maxLenght, dp[curr]);
    }
    return maxLenght;
}

int lengthOfLIS(vector<int>& nums) {
    // nums.insert(nums.begin(),-1000000000);
    // int N = 2505;
    // vector<vector<int>> dp(N, vector<int>(N, -1));
    // return rec(0,1, nums,dp);
    return getLIS(nums);
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
}