#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(int v, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[v] = true;
    for(int u : graph[v]) {
        if(!visited[u]) {
            DFS(u, graph, visited, st);
        }
    }
    st.push(v);
}

void reverseDFS(int v, vector<vector<int>>& reversedGraph, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for(int u : reversedGraph[v]) {
        if(!visited[u]) {
            reverseDFS(u, reversedGraph, visited, component);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N), reversedGraph(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reversedGraph[b].push_back(a);
    }

    stack<int> st;
    vector<bool> visited(N, false);
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            DFS(i, graph, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> SCC;
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        
        if(!visited[v]) {
            vector<int> component;
            reverseDFS(v, reversedGraph, visited, component);
            SCC.push_back(component);
        }
    }

    cout << SCC.size() << endl;
    for(auto component : SCC) {
        cout << component.size();
        for(int v : component) {
            cout << " " << v;
        }
        cout << endl;
    }

    return 0;
}