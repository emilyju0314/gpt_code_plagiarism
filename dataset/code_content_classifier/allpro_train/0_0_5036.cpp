#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tourismCities;
vector<vector<int>> adjList;

void dfs(int u, int parent) {
    tourismCities[u] = 1;
    for (int v : adjList[u]) {
        if (v != parent) {
            dfs(v, u);
            tourismCities[u] += tourismCities[v];
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    adjList.resize(n+1);
    tourismCities.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1, 0);

    vector<int> subtreeTourismCities;
    for (int i = 2; i <= n; i++) {
        subtreeTourismCities.push_back(tourismCities[i]);
    }

    sort(subtreeTourismCities.rbegin(), subtreeTourismCities.rend());

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += subtreeTourismCities[i];
    }

    cout << sum << endl;

    return 0;
}