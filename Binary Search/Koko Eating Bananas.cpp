//
// Created by esraa on 8/16/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using  namespace std;

bool validSpeed(int speed, vector<int> &piles, int h) {
        long long hours = 0;
        for (int &pile: piles) {
                if (pile%speed == 0) hours+= pile/speed;
                else hours += pile/speed + 1;
                if (hours > h) return false;
        }
        return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), initialIterations = h/n;
        sort(piles.begin(), piles.end());
        int ans = 0;

        int left = 1, right = piles[n-1];
        while (left<=right) {
                int speed = left + (right - left)/2;
                if (validSpeed(speed, piles, h)) {
                        ans = speed;
                        right = speed - 1;
                }else {
                        left = speed + 1;
                }
        }
        return ans;
}

int main() {
        vector<int> piles = {312884470};
        int h = 312884469;
        cout<<minEatingSpeed(piles, h)<<endl;
}