//
// Created by esraa on 8/29/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int rec(int curr, vector<int> &cost, vector<int> &dp) {

    if (curr == cost.size()) return 0;

    if (curr == -1) return min(rec(curr+1,cost, dp), rec(curr+2, cost, dp));

    int &ret = dp[curr];
    if (~ret) return ret;

    int climbOne = rec(curr+1, cost, dp)+ cost[curr];
    int climbTwo = 1e9;
    if (curr + 1 < cost.size()) climbTwo = rec(curr+2,cost, dp) + cost[curr];
    ret = min(climbOne, climbTwo);

    return ret;
}

int minCostClimbingStairs(vector<int>& cost) {
    // recursive solution (uncomment the next two lines of code)

    // vector<int> dp(1005, -1);
    // return rec(-1,cost, dp);


    // iterative solution
    int N = cost.size();
    vector<int>dp(N+1);
    dp[0] = dp[1] = 0;
    for (int i=2; i<=N; i++) {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[N];
}


int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<minCostClimbingStairs(cost)<<endl;
}