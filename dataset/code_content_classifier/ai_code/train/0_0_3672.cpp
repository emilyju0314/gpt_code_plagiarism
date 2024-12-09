#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 314000000;

vector<vector<pair<int, int>>> split_rules;
vector<int> min_diamonds, max_diamonds;

vector<int> topo_sort(vector<vector<int>> &graph, vector<int> &in_degree) {
    vector<int> order;
    queue<int> q;

    for (int i = 1; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return order;
}

void calculate_diamonds(int m, int n) {
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < split_rules.size(); i++) {
        for (auto rule : split_rules[i]) {
            graph[i + 1].push_back(rule.first);
            in_degree[rule.first]++;
        }
    }

    vector<int> order = topo_sort(graph, in_degree);

    min_diamonds = vector<int>(n + 1, INF);
    max_diamonds = vector<int>(n + 1, -INF);

    min_diamonds[order.back()] = max_diamonds[order.back()] = 0;

    for (int u : order) {
        for (auto rule : split_rules[u - 1]) {
            int v = rule.first;
            if (min_diamonds[v] == INF) continue;
            min_diamonds[u] = min(min_diamonds[u], min_diamonds[v] + 1);
            max_diamonds[u] = max(max_diamonds[u], max_diamonds[v] + 1);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    split_rules.resize(m);
    for (int i = 0; i < m; i++) {
        int mi, li;
        cin >> mi >> li;
        for (int j = 0; j < li; j++) {
            int val;
            cin >> val;
            split_rules[mi - 1].push_back({val, val});
        }
    }

    calculate_diamonds(m, n);

    for (int i = 1; i <= n; i++) {
        if (min_diamonds[i] == INF) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << min_diamonds[i] << " ";
            if (max_diamonds[i] == -INF) {
                cout << -2 << endl;
            } else {
                cout << min(314000000, max_diamonds[i]) << endl;
            }
        }
    }

    return 0;
}