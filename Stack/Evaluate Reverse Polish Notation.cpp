//
// Created by esraa on 8/12/2025.
//
#include <iostream>
#include <vector>
using namespace std;

bool isOperator(string c) {
        return (c=="+" || c=="-" || c=="*" || c=="/");
}

int compute(int first, int second, string op) {
        if (op == "+") return first+second;
        if (op == "-") return first-second;
        if (op == "*") return first*second;
        if (op == "/") return first/second;
}

int evalRPN(vector<string>& tokens) {
        vector<int> results;
        for (string &c: tokens) {
                if (!isOperator(c))
                        results.push_back(stoi(c));
                else {
                        int second = results.back();
                        results.pop_back();
                        int first = results.back();
                        results.pop_back();
                        results.push_back(compute(first,second,c));
                }
        }
        return results.back();
}

int main() {
        vector<string> tokens = {"4","13","5","/","+"};
        cout<<evalRPN(tokens)<<endl;
}