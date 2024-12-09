#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Road {
    int city;
    int capacity;
    int toll;
};

vector<vector<Road>> graph;
vector<int> enjoyment_values;
vector<int> max_enjoyment;
vector<int> min_cost;

void dfs(int node, int parent, int max_capacity) {
    max_enjoyment[node] = enjoyment_values[node];
    min_cost[node] = INT_MAX;
    
    for (Road& road : graph[node]) {
        int next_city = road.city;
        if (next_city == parent) continue;
        
        int new_capacity = min(max_capacity, road.capacity);
        dfs(next_city, node, new_capacity);
        
        max_enjoyment[node] = max(max_enjoyment[node], max_enjoyment[next_city]);
        min_cost[node] = min(min_cost[node], min_cost[next_city]);
    }
    
    if (max_capacity >= 1) {
        min_cost[node] = min(min_cost[node], road.toll);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    graph.resize(n);
    enjoyment_values.resize(n);
    max_enjoyment.resize(n);
    min_cost.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> enjoyment_values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        graph[a - 1].push_back({b - 1, c, t});
        graph[b - 1].push_back({a - 1, c, t});
    }

    dfs(0, -1, INT_MAX);

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        int max_enjoyment_value = max_enjoyment[x - 1];
        int cost_per_vehicle = min_cost[x - 1];
        cout << max_enjoyment_value << " " << cost_per_vehicle << endl;
    }

    return 0;
}