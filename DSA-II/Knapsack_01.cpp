#include <bits/stdc++.h>

using namespace std;

void knapsack(int W, vector<int> weights, vector<int> values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

// Outer Vector represents the Row i.e items
// Inner Vector represents the Column i.e weight
// Fill the DP table

    for (int i = 1; i <= n; i++) {

 //The reason for starting the loop from i = 1 instead of i = 0 is because the 
//first row of the DP table (dp[0][w]) corresponds to the case where no items are included in the knapsack (i.e., i = 0).
 //When no items are considered (i = 0), the maximum value for any capacity w is 0, because the knapsack is empty.
        
        for (int w = 0; w <= W; w++) {

//When the knapsack has 0 capacity (w = 0), regardless of the number of items
// the maximum value that can be obtained is always 0.
//Starting with w = 0 is necessary because it represents the base case where the knapsack has no capacity,
// and the maximum value for a knapsack with no capacity is always 0.
          
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout<< dp[n][W] <<endl;

     int w = W;
    cout << "Items included: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {  // Item i was included
            cout << i << " ";  // Print the item index (1-based index)
            w -= weights[i - 1];  // Reduce the remaining capacity
//After the item has been included I need to reduce the remaining capacity of the Knapsack
//In the DP table, the items are indexed from 1 to n (for convenience), but the weights and values arrays are 0-indexed.
        }
    }
    cout << endl;

}

int main() {
    
    int n = 4;     
    int W = 50; 
    vector<int> weights = {10, 20, 30, 40};
    vector<int> values = {60, 100, 120, 150};

  knapsack(W, weights, values);

}
