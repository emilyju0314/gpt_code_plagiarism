#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<pair<int, int>> requirements(m);
    for (int i = 0; i < m; i++) {
        cin >> requirements[i].first >> requirements[i].second;
    }

    vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = scores[i];
    }

    for (int i = 0; i < m; i++) {
        int u = requirements[i].first - 1;
        int v = requirements[i].second - 1;
        long long diff = result[v] - result[u] + 1;
        if (diff > 0) {
            result[u] -= diff;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}