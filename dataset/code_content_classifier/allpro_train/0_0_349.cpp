#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void solveGraph(int n, int m, vector<vector<int>>& edges) {
    vector<int> matching;
    unordered_set<int> vertices;

    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if(vertices.find(u) == vertices.end() && vertices.find(v) == vertices.end()) {
            matching.push_back(i+1);
            vertices.insert(u);
            vertices.insert(v);
        }
    }

    if(matching.size() >= n) {
        cout << "Matching" << endl;
        for(int i = 0; i < n; i++) {
            cout << matching[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IndSet" << endl;
        unordered_set<int> independentSet;
        for(int i = 1; i <= 3*n; i++) {
            if(vertices.find(i) == vertices.end()) {
                independentSet.insert(i);
                if(independentSet.size() == n) break;
            }
        }
        for(int vertex : independentSet) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(2));
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i][0] = u;
            edges[i][1] = v;
        }

        solveGraph(n, m, edges);
    }

    return 0;
}