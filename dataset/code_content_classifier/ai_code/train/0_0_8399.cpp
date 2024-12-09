#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int parent, distance;
};

int main() {
    int n;
    cin >> n;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 2; i <= n; i++) {
        int p, d;
        cin >> p >> d;
        graph[p].push_back({i, d});
    }

    vector<int> answer(n + 1);
    vector<int> depth(n + 1);
    function<void(int, int)> dfs = [&](int node, int d) {
        depth[node] = d;
        for (const Edge& edge : graph[node]) {
            dfs(edge.parent, d + edge.distance);
        }
    };

    dfs(1, 0);

    for (int k = 1; k <= n; k++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += min(depth[i], depth[i] + k - 2 * min(depth[i], k));
            cout << sum << endl;
        }
    }

    return 0;
}