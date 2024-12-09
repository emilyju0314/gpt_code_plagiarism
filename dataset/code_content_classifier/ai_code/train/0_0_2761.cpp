#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(int node, unordered_map<int, vector<int>>& adj_list, unordered_map<int, vector<int>>& rev_adj_list, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;
    for (int next : adj_list[node]) {
        if (!visited[next]) {
            if (!dfs(next, adj_list, rev_adj_list, visited, order)) {
                return false;
            }
        }
    }
    order.push_back(node);
    return true;
}

void assign(int node, int direction, unordered_map<int, int>& assignment, unordered_map<int, vector<int>>& rev_adj_list) {
    assignment[node] = direction;
    for (int prev : rev_adj_list[node]) {
        if (assignment[prev] == -1) {
            assign(prev, 1 - direction, assignment, rev_adj_list);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, vector<int>> rev_adj_list;
    vector<pair<int, int>> conveyors;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        rev_adj_list[y].push_back(x);
        conveyors.push_back({x, y});
    }

    int k;
    cin >> k;
    vector<pair<int, int>> transfers;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        transfers.push_back({a, b});
    }

    vector<bool> visited(n + 1, false);
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (!dfs(i, adj_list, rev_adj_list, visited, order)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    unordered_map<int, int> assignment;
    for (int i = 1; i <= n; i++) {
        assignment[i] = -1;
    }

    for (int i = n - 1; i >= 0; i--) {
        int node = order[i];
        if (assignment[node] == -1) {
            assign(node, 0, assignment, rev_adj_list);
        }
    }

    cout << "Yes" << endl;
    for (auto conveyor : conveyors) {
        int direction = assignment[conveyor.first] < assignment[conveyor.second] ? 0 : 1;
        cout << conveyor.first << " " << conveyor.second << " " << direction << endl;
    }

    return 0;
}