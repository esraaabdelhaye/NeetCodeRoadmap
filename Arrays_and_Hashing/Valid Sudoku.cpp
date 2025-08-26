//
// Created by esraa on 8/7/2025.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9][9] = {0}, cols[9][9] = {0}, squares[9][9] = {0};

    for (int row=0; row<9; row++) {
        for (int col=0; col<9; col++) {
            if (board[row][col] == '.') continue;
            int idx = board[row][col] - '0' - 1;
            int squareIdx = col/3 + (row/3)*3;
            if (rows[row][idx] || cols[col][idx] || squares[squareIdx][idx]) return false;

            rows[row][idx] = cols[col][idx] = squares[squareIdx][idx] = 1;
        }
    }
    return true;
}

int main() {

    return 0;
}