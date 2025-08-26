//
// Created by esraa on 8/4/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> pair_idx;
        int n=nums.size();
        for (int i=0; i<n; i++)
                pair_idx.push_back(make_pair(nums[i],i));

        sort(pair_idx.begin(), pair_idx.end());
        int left = 0, right = n-1;
        while (left<right) {
                int sum = pair_idx[left].first + pair_idx[right].first;
                if (sum == target)
                        return {(pair_idx[left].second), (pair_idx[right].second)};

                if (sum < target)
                        left++;
                else right--;
        }

        return {};
}

int main() {

}