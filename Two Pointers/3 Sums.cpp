//
// Created by esraa on 8/10/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void searchForTriples(vector<int> &nums, vector<vector<int>> &ans) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++) {
        if (nums[i] > 0) break;
        if (i>0 && nums[i] == nums[i-1]) continue;

        int first = nums[i], left = i+1, right = n-1;
        while (left < right) {
            if (nums[left] + nums[right] + first == 0) {
                ans.push_back({first, nums[left], nums[right]});
                left++;
                while (left<right && nums[left] == nums[left-1]) {
                    left++;
                }

            }
            if (nums[left] + nums[right] + first < 0) left++;
            else right--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    searchForTriples(nums, ans);
    return ans;
}

int main() {
    // {-10,-5,-5,-4,-4,-3,-2,-2,0,0,1,2,2,2,2,5,5}
    vector<int> nums = {0,0,0,0,0,0};
    vector<vector<int>> ans = threeSum(nums);
    for (auto vec: ans) {
        for (int num: vec) cout<<num<<" ";
        cout<<endl;
    }
}