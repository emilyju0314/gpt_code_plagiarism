#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool checkRoute(const unordered_map<int, vector<int>>& graph, int start, int goal) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (visited[curr]) continue;
        visited[curr] = true;
        
        if (curr == goal) return true;
        
        for (int next : graph.at(curr)) {
            q.push(next);
        }
    }
    
    return false;
}

int main() {
    int a, b;
    
    while (true) {
        unordered_map<int, vector<int>> graph;
        
        while (true) {
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        if (graph.empty()) break;
        
        if (checkRoute(graph, 1, 2) && checkRoute(graph, 1, 2) && checkRoute(graph, 1, 2)) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }
    
    return 0;
}