#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Edge {
    int u, v;
    char c;
};

map<pair<int, int>, string> edgeStrings;
vector<string> strings;
vector<vector<int>> adjList;

void dfs(int u, int parent, string currPath) {
    for (int v : adjList[u]) {
        if (v != parent) {
            edgeStrings[{u, v}] = currPath + edgeStrings[{u, v}];
            dfs(v, u, currPath + edgeStrings[{u, v}]);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    adjList.resize(n + 1);
    vector<Edge> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;

        edges[i] = {u, v, c};
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        edgeStrings[{u, v}] = c;
        edgeStrings[{v, u}] = c;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, -1, "");
    }

    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        
        u--; v--;

        int count = 0;
        for (int j = l - 1; j < r; j++) {
            string strUV = edgeStrings[{min(u, v) + 1, max(u, v) + 1}];
            string searchString = strings[j];
            size_t pos = searchString.find(strUV, 0);
            while (pos != string::npos) {
                count++;
                pos = searchString.find(strUV, pos + 1);
            }
        }

        cout << count << endl;
    }

    return 0;
}