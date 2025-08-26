//
// Created by esraa on 8/7/2025.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1, zerosCount = 0;
        vector<int> res(n);

        for (int i=0; i<n; i++) {
                if (nums[i] == 0) {
                    zerosCount++;
                    continue;
                }
            product*=nums[i];
        }

        for (int i=0; i<n; i++) {
            if (nums[i]==0 && zerosCount == 1) {
                res[i] = product;
            }
            else {
                if (zerosCount) res[i] = 0;
                else res[i] = product/nums[i];
            }
        }

    return res;
}

int main() {
    //vector<int> nums = {-1,1,0,-3,3};
    vector<int> nums = {1,0};
    vector<int> res = productExceptSelf(nums);
    for (int num: res) cout<<num<<" ";
    cout<<endl;
}