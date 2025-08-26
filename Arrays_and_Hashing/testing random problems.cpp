//
// Created by esraa on 8/5/2025.
//
#include <iostream>
#include <optional>
#include <vector>
#include <unordered_map>
using namespace std;

void bestSum(int idx,int target, vector<int> &nums, int &calls, vector<int> &curr, vector<int> &ans, unordered_map<int,vector<int>> &memo) {
    calls++;
    if (memo.count(target)) {
        ans = memo[target];
        return;
    }
    if (target<0) return;
    if (target == 0) {
        if (!ans.empty() && ans.size()>curr.size() || ans.empty()) {
            ans = curr;
            memo[target]= ans;
        }
        return;
    }

    for (int i=idx; i<nums.size(); i++){
        int num = nums[i];
        curr.push_back(num);
        bestSum(i,target-num,nums,calls,curr,ans,memo);
        curr.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,5,25};
    unordered_map<int, vector<int>> memo;
    int target = 100;
    int calls = 0;
    vector<int> curr;
    vector<int> ans;

    bestSum(0,target, nums,calls,curr, ans, memo);
    for (int num:ans) cout<<num<<" ";
    cout<<endl;
    cout<<"Function was called: "<<calls<<" times"<<endl;
}