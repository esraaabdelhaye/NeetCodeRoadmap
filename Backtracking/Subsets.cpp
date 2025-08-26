//
// Created by esraa on 8/6/2025.
//
#include <iostream>
#include <vector>
using namespace std;

void getSubsets(int idx, vector<int> nums, vector<int>& curr, vector<vector<int>> &ans) {
    if (idx == nums.size()) {
        ans.push_back(curr);
        return;
    }

    int num = nums[idx];
    curr.push_back(num);

    getSubsets(idx+1, nums,curr,ans);
    curr.pop_back();
    getSubsets(idx+1, nums,curr,ans);

}

vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr;
       getSubsets(0,nums,curr,ans);
       return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);

    for (auto vec:ans) {
        for (int num:vec) cout<<num<<" ";
        cout<<endl;
    }
    cout<<"size: "<<ans.size()<<endl;
}