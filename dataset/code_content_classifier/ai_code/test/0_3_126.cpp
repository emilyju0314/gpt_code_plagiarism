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

    vector<int> updated_scores = scores;
    for (int i = 0; i < m; i++) {
        int u = requirements[i].first - 1;
        int v = requirements[i].second - 1;
        
        updated_scores[v] = min(updated_scores[v], updated_scores[u]);
    }

    for (int i = 0; i < m; i++) {
        int u = requirements[i].first - 1;
        int v = requirements[i].second - 1;

        updated_scores[u] = min(updated_scores[u], updated_scores[v]);
    }

    for (int i : updated_scores) {
        cout << i << " ";
    }

    return 0;
}