#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int city;
    int capacity;
    int toll;
};

vector<vector<Road>> graph;
vector<int> enjoyment_values;
vector<pair<int, int>> max_enjoyment_toll;

void dfs(int city, int parent, int v, int max_enjoyment, int max_toll) {
    max_enjoyment = max(max_enjoyment, enjoyment_values[city]);
    max_toll = max(max_toll, max_enjoyment);
    
    for (const Road& road : graph[city]) {
        if (road.city != parent && road.capacity >= v) {
            dfs(road.city, city, v, max_enjoyment, max_toll);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    graph.resize(n);
    enjoyment_values.resize(n);
    max_enjoyment_toll.resize(q);

    for (int i = 0; i < n; i++) {
        cin >> enjoyment_values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        graph[a - 1].push_back({b - 1, c, t});
        graph[b - 1].push_back({a - 1, c, t});
    }

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        dfs(x - 1, -1, v, 0, 0);
        max_enjoyment_toll[i] = {max_enjoyment, max_toll / v};
    }

    for (const auto& enjoy_toll : max_enjoyment_toll) {
        cout << enjoy_toll.first << " " << enjoy_toll.second << endl;
    }

    return 0;
}