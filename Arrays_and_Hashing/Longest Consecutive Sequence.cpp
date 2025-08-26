//
// Created by esraa on 8/7/2025.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1, maxCount = 1;
        sort(nums.begin(),nums.end());
        int curr = nums[0], next = curr+1;

        for (int num:nums) {
                if (num == curr)continue;
                if (num == next) {
                        count++;
                        maxCount = max(maxCount,count);
                }

                else count = 1;

                curr = num;
                next = curr+1;
        }
        return maxCount;
}

int main() {
        vector<int> arr = {};
        cout<<longestConsecutive(arr)<<endl;
}