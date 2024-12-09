#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_valid_labeling(vector<vector<int>>& adj_list, vector<int>& labels) {
    for (int i = 0; i < adj_list.size(); i++) {
        for (int j : adj_list[i]) {
            if (abs(labels[i] - labels[j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> labels(n, 0);
    for (int i = 0; i < n; i++) {
        labels[i] = 1;
    }

    // Using BFS to assign labels to vertices
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    while (!q.empty() && n1 > 0) {
        int cur = q.front();
        q.pop();
        labels[cur] = 1;
        n1--;
        for (int neighbor : adj_list[cur]) {
            if (labels[neighbor] == 1) {
                q.push(neighbor); // Push back to make sure the neighbors also get labeled 1
            }
        }
    }

    while (!q.empty() && n2 > 0) {
        int cur = q.front();
        q.pop();
        labels[cur] = 2;
        n2--;
        for (int neighbor : adj_list[cur]) {
            if (labels[neighbor] == 2) {
                q.push(neighbor);
            }
        }
    }

    while (!q.empty() && n3 > 0) {
        int cur = q.front();
        q.pop();
        labels[cur] = 3;
        n3--;
        for (int neighbor : adj_list[cur]) {
            if (labels[neighbor] == 3) {
                q.push(neighbor);
            }
        }
    }

    if (n1 == 0 && n2 == 0 && n3 == 0 && is_valid_labeling(adj_list, labels)) {
        cout << "YES" << endl;
        for (int label : labels) {
            cout << label;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}