#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> floors(n);
    int total_people = 0;
    for (int i = 0; i < n; i++) {
        cin >> floors[i];
        total_people += floors[i];
    }

    int min_cost = INT_MAX;
    for (int x = 1; x <= n; x++) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            cost += floors[i] * (abs(i - x) + i + x);
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;

    return 0;
}