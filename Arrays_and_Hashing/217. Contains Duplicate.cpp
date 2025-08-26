//
// Created by esraa on 8/4/2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,bool> found;
    for (int num:nums) {
        if (found[num]) return true;
        found[num] = true;
    }
    return false;
}

int main() {

}