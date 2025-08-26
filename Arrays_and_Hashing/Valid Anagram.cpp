//
// Created by esraa on 8/4/2025.
//
#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
       if (s.length()!=t.length()) return false;

       unordered_map<char,int> freq;
       for (char &c:s) freq[c]++;

       for (char &c:t) {
              if (freq[c]) freq[c]--;
              else return false;
       }
       return true;
}

int main() {

}
