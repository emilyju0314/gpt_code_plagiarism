#include <iostream>
#include <vector>

using namespace std;

int countPaths(int n, vector<vector<int>>& graph, int source, int current, int visited) {
    if (visited == ((1 << n) - 1)) {
        if (graph[current][source] == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !(visited & (1 << i))) {
            count += countPaths(n, graph, source, i, visited | (1 << i));
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int result = countPaths(n, graph, 0, 0, 1);
    cout << result << endl;

    return 0;
}