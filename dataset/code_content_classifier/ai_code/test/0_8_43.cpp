#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct City {
    int enjoyment;
    vector<pair<int, int>> roads; // {capacity, toll}
};

void bfs(vector<City>& cities, int start, int vehicles, int& maxEnjoyment, int& maxToll) {
    queue<int> q;
    vector<bool> visited(cities.size(), false);
    vector<int> maxEnjoyed(cities.size(), 0);
    vector<int> maxTolled(cities.size(), 0);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int currCity = q.front();
        q.pop();

        for (auto road : cities[currCity].roads) {
            int neighbor = road.first;
            int capacity = road.second.first;
            int toll = road.second.second;

            if (!visited[neighbor] && capacity >= vehicles) {
                maxEnjoyed[neighbor] = max(maxEnjoyed[currCity], cities[neighbor].enjoyment);
                maxTolled[neighbor] = max(maxTolled[currCity], toll);
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    maxEnjoyment = maxEnjoyed[start];
    maxToll = maxTolled[start];
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<City> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].enjoyment;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--; b--;
        cities[a].roads.push_back({b, {c, t}});
        cities[b].roads.push_back({a, {c, t}});
    }

    for (int i = 0; i < q; i++) {
        int vehicles, start;
        cin >> vehicles >> start;
        start--;

        int maxEnjoyment, maxToll;
        bfs(cities, start, vehicles, maxEnjoyment, maxToll);

        cout << maxEnjoyment << " " << maxToll << endl;
    }

    return 0;
}