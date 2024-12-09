#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<set<int>> requirements(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        requirements[u-1].insert(v-1);
    }

    vector<int> in_degrees(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (requirements[u].count(v) > 0) {
                in_degrees[v]++;
            }
        }
    }

    vector<pair<long long, int>> sorted_scores;
    for (int i = 0; i < n; i++) {
        sorted_scores.push_back({scores[i], i});
    }
    sort(sorted_scores.begin(), sorted_scores.end());

    for (auto& [score, u] : sorted_scores) {
        long long min_score = scores[u];
        if (in_degrees[u] == 0) {
            for (int v = 0; v < n; v++) {
                if (requirements[v].count(u) > 0) {
                    min_score = max(min_score, scores[v] + 1);
                }
            }
        } else {
            min_score = sorted_scores[in_degrees[u] - 1].first + 1;
        }
        scores[u] = min_score;
    }

    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}