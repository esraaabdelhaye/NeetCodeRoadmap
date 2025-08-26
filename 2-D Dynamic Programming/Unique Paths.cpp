//
// Created by esraa on 8/8/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int getAns(int m, int n, int memo[101][101]){
    int smaller = min(n,m), larger = max(n,m);
    if (memo[smaller][larger])
        return memo[smaller][larger];
    if (n==1 || m==1) return 1;
    if (n==0 || m==0) return 0;

    memo[smaller][larger] = getAns(n,m-1, memo) + getAns(n-1, m,memo);
    return memo[smaller][larger];
}

int uniquePaths(int m, int n) {
    int memo[101][101] = {-1};
    return getAns(m,n,memo);
}
int main() {
    int n,m;
    cin>>m>>n;
    cout<<uniquePaths(m,n)<<endl;
}