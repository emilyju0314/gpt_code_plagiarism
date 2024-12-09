#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> buildings;
    for (int i = 0; i < n; i++) {
        int v, c;
        cin >> v >> c;
        buildings.push_back({v, c});
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int v = buildings[i].first;
        int c = buildings[i].second;

        long long secs = (s + v - 1) / v; // ceil(s/v) - calculate number of seconds needed to reach s cookies
        long long cost = secs * c; // total cost to build the building 

        ans = max(ans, cost + secs);
    }

    cout << ans << endl;

    return 0;
}