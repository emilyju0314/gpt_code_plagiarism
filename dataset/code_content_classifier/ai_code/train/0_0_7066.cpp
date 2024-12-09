#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    long long totalCost = 0;
    vector<pair<int, int>> flights;
    for (int i = 0; i < n; i++) {
        flights.push_back({c[i], i + 1});
    }

    sort(flights.begin(), flights.end());

    vector<int> departureTimes(n);
    for (int i = 0; i < n; i++) {
        int t = k + i + 1;
        totalCost += (t - flights[i].second) * flights[i].first;
        departureTimes[flights[i].second - 1] = t;
    }

    cout << totalCost << endl;
    for (int i = 0; i < n; i++) {
        cout << departureTimes[i] << " ";
    }
    cout << endl;

    return 0;
}