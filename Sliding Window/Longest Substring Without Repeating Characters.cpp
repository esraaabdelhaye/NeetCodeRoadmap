//
// Created by esraa on 8/22/2025.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int maxCount = 0, currCount = 0;
    map<char,int> freq;
    int leftPtr = 0, rightPtr = 0;

    while (rightPtr<s.size()) {

        if (freq[s[rightPtr]] == 0) {
            currCount++;
            freq[s[rightPtr]]++;
            rightPtr++;

            maxCount = max(maxCount,currCount);

        }else {
            while (freq[s[rightPtr]]>0) {
                freq[s[leftPtr]]--;
                leftPtr++;
                currCount--;
            }
        }
    }

    return maxCount;
}