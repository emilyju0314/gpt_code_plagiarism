#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> values;
vector<int> steps;

int dfs(int v, int step) {
    if (values[v] == 0) {
        return -1;
    }
    
    values[v]--;
    step++;
    sort(graph[v].begin(), graph[v].end());

    for (int c : graph[v]) {
        if (dfs(c, step) == -1) {
            return -1;
        }
    }

    if (values[v] == 0) {
        return -1;
    }

    values[v]--;
    step++;

    return step;
}

int main() {
    int N;
    cin >> N;

    graph.resize(N + 1);
    values.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> values[i];
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        steps.push_back(dfs(i, 0));
    }

    for (int s : steps) {
        cout << s << endl;
    }

    return 0;
}