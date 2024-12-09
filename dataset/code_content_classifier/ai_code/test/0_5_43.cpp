#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Road {
    int city;
    int capacity;
    int toll;
};

vector<vector<Road>> adj;
vector<int> enjoyment;
int maxEnjoyment;
int minToll;

void dfs(int city, int parent, int v, int maxCapacity) {
    if (enjoyment[city] > maxEnjoyment) {
        maxEnjoyment = enjoyment[city];
        minToll = INT_MAX;
    }

    for (auto road : adj[city]) {
        if (road.city == parent) continue;

        int updatedCapacity = min(v, road.capacity);
        if (updatedCapacity >= maxCapacity) {
            minToll = min(minToll, road.toll);

            dfs(road.city, city, v, updatedCapacity);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    adj.resize(n + 1);
    enjoyment.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> enjoyment[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        adj[a].push_back({b, c, t});
        adj[b].push_back({a, c, t});
    }

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;

        maxEnjoyment = 0;
        minToll = INT_MAX;
        dfs(x, -1, v, v);

        cout << maxEnjoyment << " " << (minToll == INT_MAX ? 0 : minToll) << endl;
    }

    return 0;
}