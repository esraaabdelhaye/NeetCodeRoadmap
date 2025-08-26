//
// Created by esraa on 8/15/2025.
//
#include <iostream>
#include <vector>
using  namespace std;

int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, minNum = INT_MAX;
        while (left <= right) {
                int mid = left + (right - left)/2;

                if (nums[mid] <= nums[left] && nums[mid] <= nums[right]){
                        minNum = min(nums[mid], minNum);
                }

                if (nums[mid] <= nums[right]) right = mid - 1;
                else if (nums[mid] >= nums[left]) left = mid + 1;

        }
        return minNum;
}

int main() {

}