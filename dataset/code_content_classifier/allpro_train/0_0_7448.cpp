#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> scores(n);
    vector<int> sum_scores(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> scores[i].first >> scores[i].second;
    }

    vector<vector<int>> hates(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        hates[u].push_back(v);
        hates[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (find(hates[i].begin(), hates[i].end(), j) == hates[i].end()) {
                    sum_scores[i] += min(scores[i].first + scores[j].second, scores[i].second + scores[j].first);
                }
            }
        }
        cout << sum_scores[i] << " ";
    }

    return 0;
}