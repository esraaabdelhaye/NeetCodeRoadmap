//
// Created by esraa on 8/7/2025.
//
#include <iostream>
#include <ranges>
#include <vector>
#include <unordered_map>
using namespace std;

void getPermutations(int idx, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, unordered_map<int,bool> taken) {
    if (curr.size()==nums.size()) {
        ans.push_back(curr);
        return;
    }

    for (int i=0; i<nums.size(); i++) {
        if (taken[nums[i]]) continue;
        curr.push_back(nums[i]);
        taken[nums[i]] = true;
        getPermutations(idx+1,nums,curr,ans,taken);

        taken[nums[i]] = false;
        curr.pop_back();
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int,bool> taken;
    vector<int> curr;
    getPermutations(0,nums,curr,ans,taken);
    return ans;
}

int main() {


}