#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int from, to, beauty;
};

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<vector<Road>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({a, b, c});
        adj[b].push_back({b, a, c});
    }

    vector<int> visited(n + 1, 0);
    vector<int> beauty;
    int start, end;

    function<void(int, int)> dfs = [&](int node, int sum) {
        visited[node] = 1;
        for (Road road : adj[node]) {
            if (!visited[road.to]) {
                beauty.push_back(road.beauty);
                if (road.to == end) {
                    return;
                } else {
                    dfs(road.to, sum + road.beauty);
                    if (beauty.size() >= l && beauty.size() <= r) {
                        sort(beauty.begin(), beauty.end());
                        int median = beauty[beauty.size() / 2];
                        if (median <= sum) {
                            start = node;
                            end = road.to;
                        }
                    }
                    beauty.pop_back();
                }
            }
        }
    };

    start = 1;
    end = 1;
    dfs(1, 0);

    cout << end << " " << start << endl;

    return 0;
}