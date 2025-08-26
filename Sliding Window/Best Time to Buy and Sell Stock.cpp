#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int left = 0, right = 1, profit = 0;
        while (right < prices.size()) {
                if (prices[left] > prices[right])
                        left = right;
                else
                        profit = max(profit, prices[right] - prices[left]);

                right++;
        }
        return profit;
}

int main() {

}