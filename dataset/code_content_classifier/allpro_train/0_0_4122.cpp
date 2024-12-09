#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> graph;
vector<int> regionImportance;
vector<int> colors;
vector<int> colorUsed;

int getNextColor() {
    for (int i = 1; i <= 20; i++) {
        if (colorUsed[i] == 0) {
            colorUsed[i] = 1;
            return i;
        }
    }
    return -1;
}

void colorRegions(int u, int parentColor) {
    int color = getNextColor();
    colors[u] = color;

    for (int v : graph[u]) {
        if (regionImportance[v] > regionImportance[u] || colors[v] == parentColor) {
            colorRegions(v, color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    regionImportance.resize(n + 1);
    colors.resize(n + 1);
    colorUsed.resize(21);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> regionImportance[i];
    }

    vector<pair<int, int>> regions;
    for (int i = 1; i <= n; i++) {
        regions.push_back({regionImportance[i], i});
    }

    sort(regions.begin(), regions.end());

    for (int i = 0; i < n; i++) {
        int u = regions[i].second;
        if (colors[u] == 0) {
            colorRegions(u, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}