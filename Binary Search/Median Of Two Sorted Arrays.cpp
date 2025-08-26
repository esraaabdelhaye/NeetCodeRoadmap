//
// Created by esraa on 8/17/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2) {
    arr2.insert(arr2.begin(), arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int m = arr2.size();
    if (arr2.size()%2) return arr2[m/2];
    return (arr2[m/2 - 1] + arr2[m/2])/2.0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n <= m) return findMedian(nums1, nums2);
    return findMedian(nums2, nums1);
}

int main() {
    vector<int> arr1 = {};
    vector<int> arr2 = {};

    cout<<findMedianSortedArrays(arr1, arr2)<<endl;
}