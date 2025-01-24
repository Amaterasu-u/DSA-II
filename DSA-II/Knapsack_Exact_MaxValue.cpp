#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int unboundedKnapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<int> dp(W + 1, 0); 
    
//Initialize a DP array dp[] where dp[0] = 0, because if the capacity is 0, no value can be taken (i.e., the maximum value is 0).

// DP array to store the maximum value at each capacity
//We will use an array dp[] of size W + 1 (from 0 to W) to store the maximum value that can be obtained for each weight capacity.

    // Fill the DP table

    //For each weight capacity w, we check each item (with its weight and value).
//For each item, we check if it can fit in the current knapsack capacity w. If it can, we calculate:
//The maximum value for the current capacity w by including the current item. This is given by:
//dp[w] = max(dp[w], dp[w - weight[i]] + value[i])
//This means: either we do not include the current item, and the value remains dp[w] from before, or we include it,
 //and we update dp[w] to the value obtained by adding the current item to the previous value
 // (when the remaining weight is w - weight[i]).


    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) { // If item can be included in the knapsack
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }

    return dp[W]; // Maximum value for the full knapsack capacity W
}

int main() {
    int n = 3; // Number of items
    int W = 10; // Knapsack capacity

    vector<int> weights = {2, 3, 5}; // Weights of the items
    vector<int> values = {5, 7, 10}; // Values of the items

    int result = unboundedKnapsack(W, weights, values, n);

    cout << "Maximum value: " << result << endl;  // Expected output: 30
    return 0;
}
