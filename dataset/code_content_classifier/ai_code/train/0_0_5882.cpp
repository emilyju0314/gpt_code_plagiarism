#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    bool used;
};

int dfs(int v, vector<vector<Edge>>& graph, int T, vector<int>& used, int parent) {
    if (v == T) return 1;
    
    used[v] = 1;
    for (Edge& e : graph[v]) {
        if (e.used || e.to == parent) continue;
        if (!used[e.to]) {
            if (dfs(e.to, graph, T, used, v)) {
                e.used = true;
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    int N, M, S, T;
    while (cin >> N >> M >> S >> T) {
        if (N == 0 && M == 0 && S == 0 && T == 0) break;
        
        vector<vector<Edge>> graph(N+1);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back({b, false});
        }
        
        vector<int> used(N+1, 0);
        int max_trucks = 0;
        for (int i = 1; i <= N; i++) {
            fill(used.begin(), used.end(), 0);
            max_trucks += dfs(S, graph, T, used, -1);
        }
        
        int reversed = 0;
        for (int i = 1; i <= N && !reversed; i++) {
            for (Edge& e : graph[i]) {
                e.used = true;
                int trucks = 0;
                for (int j = 1; j <= N; j++) {
                    fill(used.begin(), used.end(), 0);
                    trucks += dfs(S, graph, T, used, -1);
                }
                e.used = false; // revert back
                
                if (trucks < max_trucks) {
                    reversed = 1;
                    break;
                }
            }
        }
        
        if (reversed) {
            cout << max_trucks << " " << 1 << endl;
        } else {
            cout << max_trucks << " " << 0 << endl;
        }
    }

    return 0;
}