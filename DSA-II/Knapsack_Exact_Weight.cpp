#include <bits/stdc++.h>

using namespace std;

void isSubsetSumPossible(int W, const vector<int>& weights) {
    int n = weights.size();

    // DP table initialization
    vector<vector<bool>> dp(n + 1, vector<bool>(W + 1, false));

    // Base case: 0 weight is always possible (selecting no items)
    //The base case dp[i][0] = true for all i means that with a weight of 0, 
    //it's always possible to form that subset (by choosing no items).

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }


    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If we don't include the item
            dp[i][w] = dp[i - 1][w];

            // If we include the item (only if the current weight is <= w)
            if (weights[i - 1] <= w) {
                dp[i][w] = dp[i][w] || dp[i - 1][w - weights[i - 1]];
            }
        }
    }

    // The answer is in dp[n][W]
    cout<< dp[n][W]<<endl;


        int w=W;
    cout<<"Items Included: ";
    for(int i=n ; i>0 ; i--){
        if(dp[i][w]!=dp[i-1][w]){
            cout<<i<<" ";
            w-=weights[i-1];
        }

    }
}

int main() {
    int W = 9;
    vector<int> weights = {3, 2, 1, 4, 5}; 

    isSubsetSumPossible(W, weights);
}
/*
Step-by-Step DP Table Update:
Let's focus on i = 3 (the 3rd item) and w = 6 (weight 6):

Exclude the current item:
dp[3][6] = dp[2][6]
If it was possible to achieve weight 6 with the first 2 items, then we can still achieve weight 6 by excluding the 3rd item.
Include the current item (Item 3, weight 1):
We can include item 3 because its weight 1 is less than or equal to 6.
dp[3][6] = dp[3][6] || dp[2][6 - 1]
This means, if we can achieve weight 5 with the first 2 items (i.e., dp[2][5] is true), then adding item 3 will
 allow us to achieve weight 6.
For dp[3][6]:
If dp[2][6] was true (i.e., it's possible to get weight 6 using the first 2 items), or if dp[2][5] was true 
(i.e., it's possible to get weight 5 using the first 2 items, and we can add item 3's weight 1 to reach 6), 
then dp[3][6] will become true.
*/