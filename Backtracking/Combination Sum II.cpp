//
// Created by esraa on 8/7/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int idx, int target, vector<vector<int>> &ans,vector<int> &curr, vector<int> &nums) {
        if (target==0) {
                ans.push_back(curr);
                return;
        }
        if (target <0) return;


        for (int i=idx; i<nums.size(); i++) {
                if (i>idx && nums[i] == nums[i-1]) continue;

                curr.push_back(nums[i]);
                solve(i+1,target-nums[i], ans, curr, nums);

                curr.pop_back();
        }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //unordered_map<int,vector<int>> memo;
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,target,ans,curr,candidates);

        return ans;
}

int main() {
        vector<int> nums = {2,5,2,1,2};
        vector<vector<int>> ans = combinationSum2(nums,5);

        for (auto vec:ans) {
                for (int num:vec) cout<<num<<" ";
                cout<<endl;
        }
}