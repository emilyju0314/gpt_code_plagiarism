#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int totalCycles = 0;

void countCycles(int start, int current, int len) {
    visited[current] = true;
    
    if (len >= 4 && len <= n) {
        totalCycles++;
    }

    for (int next : graph[current]) {
        if (visited[next] && next == start && len >= 3) {
            totalCycles++;
        } else if (!visited[next]) {
            countCycles(start, next, len + 1);
        }
    }
    
    visited[current] = false;
}

int main() {
    cin >> n >> m;
    
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        countCycles(i, i, 1);
    }

    cout << totalCycles << endl;

    return 0;
}