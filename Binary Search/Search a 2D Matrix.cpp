//
// Created by esraa on 8/15/2025.
//
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int up = 0, down = n-1, targetRow = -1;

    while (up<=down) {
        int mid = up + (down-up)/2;
        if (matrix[mid][0] <= target && matrix[mid][m-1] >= target) {
            targetRow = mid;
            break;
        }

        if (matrix[mid][0] < target) up = mid+1;
        else down = mid-1;
    }

    if (targetRow != -1) {
        int left = 0, right = m-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[targetRow][mid] == target) return true;

            if (matrix[targetRow][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return false;
}

int main(){

 }