#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value, weight;
};

bool compare(const Item &a, const Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(int n, double W, vector<double> &weights, vector<double> &values) {
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {values[i], weights[i]};
    }

    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);//Compares two elements at a time using the compare function.

    double maxValue = 0.0; // To store the maximum value
    for (const auto &item : items) {
        if (W == 0) break; // Knapsack is full

        if (item.weight <= W) {
            // Take the entire item
            maxValue += item.value;
            W -= item.weight;
        } else {
            // Take a fraction of the item
            maxValue += (item.value / item.weight) * W;
            W = 0;
        }
    }

    return maxValue;
}

int main() {
    int n = 3;
    double W = 50; 
    vector<double> weights = {10, 40, 20}; // Weights of items
    vector<double> values = {60, 100, 120}; // Values of items

    double maxValue = fractionalKnapsack(n, W, weights, values);
    cout << "Maximum value: " << maxValue << endl;


}
