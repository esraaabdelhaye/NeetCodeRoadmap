//
// Created by esraa on 8/5/2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <optional>
using namespace std;

optional<vector<int>> getAns(vector<int>& candidates, unordered_map<int,vector<int>> &memo, int target,int &calls) {
    calls++;
    if (target == 0) return vector<int>{};
    if (target < 0) return nullopt;
    if (memo.count(target)) return memo[target];

    cout<<"start of target: "<<target<<endl;
    vector<int> shortestPathOfTarget;     // {} empty vector means null
    for (int num: candidates) {

        optional<vector<int>> res = getAns(candidates,memo,target-num, calls);
        if (res.has_value()) {
            vector<int> currComb = *res;
            currComb.push_back(num);
            if (shortestPathOfTarget.empty() || (!shortestPathOfTarget.empty() && shortestPathOfTarget.size()> currComb.size()))
                shortestPathOfTarget = currComb;
        }

    }

    cout<<"end of target: "<<target<<endl;
    if (!shortestPathOfTarget.empty()) {
        memo[target] = shortestPathOfTarget;
        return memo[target];
    }

    return nullopt;
}


int main() {
    vector<int> nums = {2,3,6,7,25};
    unordered_map<int, vector<int>> memo;
    vector<int> curr;
    int calls= 0;
    auto ans = getAns(nums,memo,100,calls);

    if (ans.has_value()) {
         for (int num:ans.value())
           cout<<num<<" ";
        cout<<endl;
    }
    cout<<"Number of calls: "<<calls<<endl;
}