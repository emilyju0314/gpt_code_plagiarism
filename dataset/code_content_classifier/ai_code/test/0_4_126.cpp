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
        int u, v;
        cin >> u >> v;
        requirements[i] = make_pair(u, v);
    }

    vector<long long> new_scores(n);

    for (int i = 0; i < n; i++) {
        new_scores[i] = scores[i];
    }

    for (int i = 0; i < m; i++) {
        int u = requirements[i].first;
        int v = requirements[i].second;

        long long diff = scores[v - 1] - scores[u - 1] + 1;
        
        new_scores[u - 1] += diff;
    }

    for (int i = 0; i < n; i++) {
        cout << new_scores[i] << " ";
    }

    return 0;
}