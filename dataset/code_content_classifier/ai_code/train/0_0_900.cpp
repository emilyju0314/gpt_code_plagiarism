#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    long long min_cost = 0;
    long long current_cost = 0;

    for (int i = 1; i < n; i++) {
        if (i == 1 || heights[i] < heights[i-1]) {
            current_cost = costs[i] + current_cost;
        } else {
            min_cost += current_cost * heights[i-1];
            current_cost = 0;
        }
    }

    cout << min_cost << endl;

    return 0;
}