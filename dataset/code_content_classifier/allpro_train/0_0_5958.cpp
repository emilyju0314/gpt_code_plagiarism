#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> roads;
bool visited[101];

pair<int, int> dfs(int u) {
    visited[u] = true;
    pair<int, int> res = {0, 0};
    
    for (auto edge : graph[u]) {
        int v = edge.first;
        int w = edge.second;
        
        if (!visited[v]) {
            pair<int, int> sub_res = dfs(v);
            res.first = max(res.first, sub_res.first + w);
            res.second += sub_res.second;
        }
    }
    
    return res;
}

int main() {
    cin >> N >> M;
    
    graph.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
        graph[t].push_back({s, d});
        roads.push_back({d, i});
    }
    
    sort(roads.rbegin(), roads.rend());
    
    long long max_distance = 0;
    int num_combinations = 1;
    
    for (int i = 0; i < M; i++) {
        fill(visited, visited + N + 1, false);
        int d = roads[i].first;
        vector<bool> used(M, false);
        
        for (int j = 1; j <= N; j++) {
            if (!visited[j]) {
                pair<int, int> res = dfs(j);
                max_distance = max(max_distance, res.first + d);
                num_combinations = (num_combinations * (1 + res.second)) % MOD;
            }
        }
    }
    
    cout << max_distance << " " << num_combinations << endl;
    
    return 0;
}