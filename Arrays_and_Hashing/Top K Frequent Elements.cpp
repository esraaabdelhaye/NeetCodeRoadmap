//
// Created by esraa on 8/4/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq_mp;
    priority_queue<pair<int,int>> pq;

    vector<int> ans;
    for (int &num:nums)
        freq_mp[num]++;

    for (auto &[num,index]:freq_mp) pq.push({index,num});

    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,2,2,1,3};
    vector<int> ans = topKFrequent(nums,2);
    for (int num:ans) cout<<num<<endl;
}
