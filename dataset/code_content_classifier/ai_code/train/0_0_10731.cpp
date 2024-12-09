#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& graph, int start, int end) {
    queue<pair<int, int>> q;
    vector<bool> visited(graph.size(), false);
    q.push({start, 0});
    
    while (!q.empty()) {
        int current = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (current == end) {
            return dist;
        }
        
        visited[current] = true;
        
        for (int i = 0; i < graph.size(); i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                q.push({i, dist + 1});
            }
        }
    }
    
    return -1; // no path found
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int M, a, b;
        cin >> M;
        
        vector<vector<int>> graph(M, vector<int>(M, 0));
        
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                cin >> graph[j][k];
            }
        }
        
        cin >> a >> b;
        
        int result = bfs(graph, a, b);
        
        if (result == -1) {
            cout << "infinity" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}