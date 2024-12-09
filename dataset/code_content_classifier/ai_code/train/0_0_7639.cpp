#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Edge {
    int type, x, y;
};

vector<vector<int>> adj;
vector<unordered_set<int>> undirectedEdges;
vector<int> inDegree;

bool topologicalSort(vector<int>& order) {
    queue<int> q;

    for (int i = 1; i < adj.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : undirectedEdges[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return order.size() == adj.size() - 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        adj.resize(n + 1);
        undirectedEdges.resize(n + 1);
        inDegree.assign(n + 1, 0);

        vector<Edge> edges;
        
        for (int i = 0; i < m; i++) {
            int ti, xi, yi;
            cin >> ti >> xi >> yi;
            if (ti == 0) {
                undirectedEdges[xi].insert(yi);
                undirectedEdges[yi].insert(xi);

                inDegree[yi]++;
            } else {
                adj[xi].push_back(yi);
                inDegree[yi]++;
            }
        }

        vector<int> order;
        if (!topologicalSort(order)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < order.size(); i++) {
                for (int v : undirectedEdges[order[i]]) {
                    cout << order[i] << " " << v << endl;
                }
            }
        }

        adj.clear();
        undirectedEdges.clear();
    }

    return 0;
}