#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<pair<int, int>> scores;
vector<bool> blocked;

int simulateWave(int numGoblins) {
    vector<bool> visited(n, false);
    int hallsPillaged = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && !blocked[i]) {
            visited[i] = true;
            hallsPillaged++;
            for (int j : adj[i])
                visited[j] = true;
        }
    }

    return max(0, numGoblins - hallsPillaged);
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n);
    blocked.resize(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        scores.emplace_back(x, y);
    }

    vector<int> actions;

    for (int i = 0; i < k; i++) {
        int bestAction = 0;
        int maxPoints = INT_MIN;

        for (int j = 0; j < n; j++) {
            blocked[j] = true;
            int currentPoints = scores[i].first - scores[i].second;
            currentPoints += simulateWave(i + 1);

            if (currentPoints > maxPoints) {
                maxPoints = currentPoints;
                bestAction = j + 1;
            }

            blocked[j] = false;
        }

        blocked[bestAction - 1] = true;
        actions.push_back(bestAction);
        actions.push_back(0);
    }

    cout << actions.size() << endl;
    for (int action : actions) {
        cout << action << " ";
    }

    return 0;
}