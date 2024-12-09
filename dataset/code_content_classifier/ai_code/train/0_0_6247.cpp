#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> stations;
vector<bool> visited;

bool assignFareZones(int station, int fareZone) {
    visited[station] = true;
    stations[station] = fareZone;

    bool possible = true;
    for (int neighbor : graph[station]) {
        if (!visited[neighbor]) {
            int nextFareZone = fareZone + 1;
            possible = possible && assignFareZones(neighbor, nextFareZone);
        } else {
            if (stations[neighbor] != fareZone + 1) {
                possible = false;
            }
        }
    }

    return possible;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    stations.resize(n);
    visited.assign(n, false);

    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<pair<int, int>> lines;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        lines.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!assignFareZones(i, 1)) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    int maxFareZone = *max_element(stations.begin(), stations.end());
    cout << maxFareZone << endl;
    for (int fareZone : stations) {
        cout << fareZone << " ";
    }
    cout << endl;

    return 0;
}