//
// Created by esraa on 8/21/2025.
//
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, K;
vector<int> coins;
int dp[1000005];


int solve(vector<int>& coins, int amount, int dp[10005]) {
    if (amount < 0) return 1e9;
    if (amount == 0) return 0;

    int &ret = dp[amount];
    if (~ret) return ret;

    ret = 1e9;
    for (int coin: coins) {
        ret = min(ret , 1 + solve(coins, amount - coin, dp));
    }

    return ret;
}

int coinChange(vector<int>& coins, int amount) {
    int dp[10005];
    memset(dp, -1, sizeof dp);
    int ans = solve(coins, amount, dp);
    if (ans == 1e9) return -1;
    return ans;
}


int main() {
    cin>>N>>K;
    coins = vector<int>(N);
    memset(dp, -1, sizeof dp);
    for (int i=0; i<N; i++) cin>>coins[i];
    int ans = coinChange(K);
    (ans == 1e9)? cout<<"-1"<<endl: cout<<ans<<endl;
}