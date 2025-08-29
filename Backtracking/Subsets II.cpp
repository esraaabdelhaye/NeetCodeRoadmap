//
// Created by esraa on 8/29/2025.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rec(int idx, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans) {
    if (idx == nums.size()) {
        ans.push_back(curr);
        return;
    }

    int num = nums[idx];
    curr.push_back(num);
    rec(idx+1, nums, curr, ans);

    curr.pop_back();
    while (idx + 1 < nums.size() && nums[idx] == nums[idx+1])
        idx++;

    rec(idx+1, nums, curr, ans);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    rec(0,nums, curr, ans);
    return ans;
}

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    cout<<"size: "<<ans.size()<<endl;
    for (auto vec:ans) {
        for (int num:vec) cout<<num<<" ";
        cout<<endl;
    }
}