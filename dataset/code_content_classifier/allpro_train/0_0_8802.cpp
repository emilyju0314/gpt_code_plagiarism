#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> prices;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        prices.push_back(make_pair(a, b));
    }

    double minCost = INT_MAX;

    for (int i = 0; i < n; i++) {
        double cost = (double) prices[i].first / prices[i].second * m;
        minCost = min(minCost, cost);
    }

    cout << fixed << setprecision(8) << minCost << endl;

    return 0;
}