//
// Created by esraa on 8/4/2025.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> patterns;

        for (string &str:strs) {
            string sorted = str;
            sort(sorted.begin(),sorted.end());

            if (patterns.count(sorted)>0) {
                int index = patterns[sorted];
                ans[index].push_back(str);

            }
            else {
                patterns.insert({sorted,patterns.size()});
                ans.push_back({str});
            }
        }
    return ans;
}

int main() {

}
