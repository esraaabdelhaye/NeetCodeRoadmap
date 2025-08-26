//
// Created by esraa on 8/13/2025.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int,int>> cars(n);

    for (int i=0; i<n; i++) {
        cars[i] = make_pair(position[i], speed[i]);
    }

    sort(cars.begin(), cars.end(), greater<pair<int, int>>());
    stack<double> st;

    for (auto &car:cars) {
        int pos = car.first;
        int spd = car.second;
        double timeTaken = (double)(target - pos) / spd;

        if (st.empty() || timeTaken > st.top()) {
            st.push(timeTaken);
        }
    }
    return st.size();
}

int main() {

}