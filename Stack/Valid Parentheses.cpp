//
// Created by esraa on 8/11/2025.
//
#include <iostream>
#include <stack>
using namespace std;

bool maching(char open, char close) {
        return (open == '{' && close == '}'
             || open == '(' && close == ')'
             || open == '[' && close == ']');
}

bool isOpening(char c) {
        return (c=='{' || c=='(' || c=='[');
}

bool isValid(string s) {
        stack<char> parentheses;
        for (char c:s) {
                if (isOpening(c)) parentheses.push(c);
                else if (!parentheses.empty() && maching(parentheses.top(),c)) parentheses.pop();
                else return false;
        }

        return parentheses.empty();
}

int main() {
        string s = "()";
        cout<<isValid(s)<<endl;
}