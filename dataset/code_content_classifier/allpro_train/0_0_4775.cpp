#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<pair<int, pair<int, int>>> wormholes;
vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> component_size;
vector<int> components;

void dfs(int node, int component) {
    visited[node] = true;
    components[node] = component;
    component_size[component]++;

    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, component);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    wormholes.resize(M);
    visited.resize(N + 1, false);
    components.resize(N + 1, -1);
    component_size.resize(N + 1, 0);
    adj_list.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        wormholes[i] = {W, {U, V}};
        adj_list[U].push_back(V);
        adj_list[V].push_back(U);
    }

    int num_components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, num_components);
            num_components++;
        }
    }

    int cost = 0;
    for (int i = 0; i < M; i++) {
        int U = wormholes[i].second.first;
        int V = wormholes[i].second.second;
        int W = wormholes[i].first;

        if (components[U] != components[V]) {
            cost ^= W;
        }
    }

    long long num_ways = 1;
    for (int i = 0; i < num_components; i++) {
        num_ways = (num_ways * component_size[i]) % MOD;
    }

    cout << cost << " " << num_ways << endl;

    return 0;
}