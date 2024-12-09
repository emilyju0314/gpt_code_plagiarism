#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& graph, vector<char>& colors, vector<int>& seconds, int node, int parent) {
    int count = 0;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            if (colors[node] != colors[neighbor]) {
                seconds[neighbor] = seconds[node] + 1;
            } else {
                seconds[neighbor] = seconds[node];
            }
            count += dfs(graph, colors, seconds, neighbor, node);
        }
    }
    return count + 1;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    vector<char> colors(N);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }

    int min_seconds = INT_MAX;
    for (int i = 0; i < N; i++) {
        vector<int> seconds(N, 0);
        seconds[i] = colors[i] == 'W' ? 1 : 0;
        int res = dfs(graph, colors, seconds, i, -1);
        min_seconds = min(min_seconds, res);
    }

    cout << min_seconds << endl;

    return 0;
}