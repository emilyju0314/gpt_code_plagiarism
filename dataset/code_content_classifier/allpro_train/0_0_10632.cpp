#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<vector<int>> graph;
vector<int> subtree_sizes;
vector<int> centroids;

void dfs(int u, int p) {
    subtree_sizes[u] = 1;
    bool is_centroid = true;
    for(int v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        subtree_sizes[u] += subtree_sizes[v];
        if(subtree_sizes[v] > N / 2) is_centroid = false;
    }
    if(N - subtree_sizes[u] > N / 2) is_centroid = false;
    if(is_centroid) centroids.push_back(u);
}

int main() {
    cin >> N;
    graph.resize(N);
    subtree_sizes.resize(N);
    
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(0, -1);
    
    if(centroids.size() == 1) {
        cout << 1 << endl;
    } else {
        map<int, vector<int>> distances;
        for(int c : centroids) distances[c] = vector<int>();
        
        queue<pair<int, int>> q;
        vector<bool> visited(N, false);
        
        for(int c : centroids) {
            q.push({c, 0});
            visited[c] = true;
            while(!q.empty()) {
                auto node = q.front(); q.pop();
                distances[c].push_back(node.second);
                for(int v : graph[node.first]) {
                    if(!visited[v]) {
                        q.push({v, node.second + 1});
                        visited[v] = true;
                    }
                }
            }
        }
        
        sort(distances[centroids[0]].begin(), distances[centroids[0]].end());
        sort(distances[centroids[1]].begin(), distances[centroids[1]].end());
        
        int ptr_a = 0, ptr_b = 0;
        int K = 1;
        while(ptr_a < distances[centroids[0]].size() && ptr_b < distances[centroids[1]].size()) {
            if(abs(distances[centroids[0]][ptr_a] - distances[centroids[1]][ptr_b]) <= 1) {
                K = 2;
                break;
            }
            if(distances[centroids[0]][ptr_a] < distances[centroids[1]][ptr_b]) {
                ptr_a++;
            } else {
                ptr_b++;
            }
        }
        
        cout << K << endl;
    }
    
    return 0;
}