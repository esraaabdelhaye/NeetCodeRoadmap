//
// Created by esraa on 8/17/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
                int mid = left + (right - left)/2;
                if (nums[mid] == target) return mid;

                if (nums[mid] < target) {
                        if (nums[right] >= target || nums[right] < nums[mid]) left = mid + 1;
                        else right = mid - 1;
                }else {
                        if (nums[right] >= target && nums[right] <= nums[mid]) left = mid + 1;
                        else right = mid - 1;
                }
        }
        return -1;
}

int main() {
        vector<int> nums = {4,5,6,7,8,1,2,3};
        int target = 8;
        cout<<search(nums, target)<<endl;
}