#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> paths(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        paths[x].push_back({y, w});
    }

    int s;
    cin >> s;

    vector<long long> mushrooms_collected(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (i == s || visited[i]) continue;

        vector<int> cycle;
        long long cycle_sum = 0;

        int cur = i;
        while (!visited[cur]) {
            visited[cur] = true;
            cycle.push_back(cur);
            for (auto& p : paths[cur]) {
                cycle_sum += p.second;
            }
            cur = paths[cur][0].first;
        }

        for (int j = 0; j < cycle.size(); j++) {
            mushrooms_collected[cycle[j]] = cycle_sum * ((j / 2) + 1);
        }
    }

    long long total_mushrooms = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            total_mushrooms += mushrooms_collected[i];
        }
    }

    cout << total_mushrooms << endl;

    return 0;
}