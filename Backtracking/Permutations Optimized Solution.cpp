#include <iostream>
#include <ranges>
#include <vector>
#include <unordered_map>
using namespace std;

void getPermutations(int idx, vector<int> &nums, vector<vector<int>> &ans) {
    if (idx==nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i=idx; i<nums.size(); i++) {
       
        swap(nums[i],nums[idx]);
        getPermutations(idx+1,nums,ans);

        swap(nums[i],nums[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getPermutations(0,nums,ans);
    return ans;
}

int main() {


}