#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> volcanoes;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        volcanoes.push_back({x, y});
    }

    sort(volcanoes.begin(), volcanoes.end());

    int ans = INT_MAX;
    for (int i = 0; i < m; ++i) {
        int steps = max(volcanoes[i].first - 1, volcanoes[i].second - 1);
        ans = min(ans, steps);
    }

    if (volcanoes.empty() || volcanoes.back().first < n || volcanoes.back().second < n) {
        ans = max(ans, n - 1);
    } 

    cout << (ans != INT_MAX ? ans : -1) << endl;

    return 0;
}