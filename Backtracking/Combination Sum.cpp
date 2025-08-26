//
// Created by esraa on 8/5/2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void getAns(int idx,vector<int>& candidates, vector<int> &curr, vector<vector<int>> &ans, int target) {
    if (target == 0) {
        ans.push_back(curr);
        return;
    }
    if (target < 0) {
        return;
    }

    for (int i=idx; i<candidates.size(); i++) {
        int num = candidates[i];
        curr.push_back(num);
        getAns(i,candidates,curr,ans,target-num);

        curr.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    getAns(0,candidates,curr,ans,target);
    return ans;
}

int main() {
    vector<int> nums = {2,3,6,7};
    vector<vector<int>> ans;
    vector<int> curr;
    getAns(0,nums,curr,ans,7);

    for (auto vec:ans) {
        for (int num:vec) cout<<num<<" ";
        cout<<endl;
    }
}