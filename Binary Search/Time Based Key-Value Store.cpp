//
// Created by esraa on 8/18/2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timeMap;
public:

    void set(string key, string value, int timestamp) {
        timeMap[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {

        string ans = "";
        int left = 0, right = timeMap[key].size()-1;
        while (left<=right) {
            int mid = left + (right - left)/2;
            if (timeMap[key][mid].first > timestamp) {
                right = mid - 1;
            }else {
                ans = timeMap[key][mid].second;
                left = mid + 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {

}