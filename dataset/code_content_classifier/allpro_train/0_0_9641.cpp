#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }

    long long total_cost = 0;
    int min_c = INT_MAX;

    for (int i = 0; i < n; i++) {
        min_c = min(min_c, cities[i].second);
        total_cost += max(cities[i].first, min_c) - cities[i].first;
    }

    cout << total_cost << endl;

    return 0;
}