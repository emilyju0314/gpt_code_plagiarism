#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> subtreeSizes;
vector<vector<int>> adjList;
vector<pair<int, int>> transformations;

void dfs(int u, int p) {
    subtreeSizes[u] = 1;
    for(int v : adjList[u]) {
        if(v != p) {
            dfs(v, u);
            subtreeSizes[u] += subtreeSizes[v];
        }
    }
}

void findTransformations(int u, int p) {
    for(int v : adjList[u]) {
        if(v != p) {
            if(subtreeSizes[v] > subtreeSizes[u]) {
                transformations.push_back({u, v, v});
                subtreeSizes[u] -= subtreeSizes[v];
                findTransformations(v, u);
            } else {
                transformations.push_back({u, v, u});
                findTransformations(v, u);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    adjList.resize(n+1);
    subtreeSizes.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, 0);
    findTransformations(1, 0);

    cout << transformations.size() << endl;
    for(auto t : transformations) {
        cout << t.first << " " << t.second << " " << t.second << endl;
    }

    return 0;
}