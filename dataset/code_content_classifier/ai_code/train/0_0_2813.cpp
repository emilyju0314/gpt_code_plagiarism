#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidTree(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> AdjList(n + 1); // Adjacency list representation of the tree
    vector<int> degree(n + 1, 0);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Check if the degree constraint is satisfied
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0 || degree[i] > 3) {
            return false;
        }
    }

    // Check if the tree is connected
    vector<bool> visited(n + 1, false);
    int components = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, AdjList, visited);
        }
    }

    return components == 1;
}

void dfs(int u, vector<vector<int>>& AdjList, vector<bool>& visited) {
    visited[u] = true;
    for (int v : AdjList[u]) {
        if (!visited[v]) {
            dfs(v, AdjList, visited);
        }
    }
}

void generatePermutations(string str, int idx, vector<string>& permutations) {
    if (idx == str.size()) {
        permutations.push_back(str);
        return;
    }

    if (str[idx] == '?') {
        for (char c = '1'; c <= '9'; c++) {
            str[idx] = c;
            generatePermutations(str, idx + 1, permutations);
        }
    } else {
        generatePermutations(str, idx + 1, permutations);
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges;

    for (int i = 0; i < n - 1; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        vector<string> perms1, perms2;
        generatePermutations(s1, 0, perms1);
        generatePermutations(s2, 0, perms2);

        bool found = false;
        for (string p1 : perms1) {
            for (string p2 : perms2) {
                int u = stoi(p1);
                int v = stoi(p2);
                if (u > n || v > n || u == v) {
                    continue;
                }
                edges.push_back({u, v});
                found = true;
                break;
            }
            if (found) break;
        }

        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << "Any possible tree edges:" << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}