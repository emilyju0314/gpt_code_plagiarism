#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> iceCreamTypes(n);
    vector<set<int>> adjList(m);

    for (int i = 0; i < n; i++) {
        int si;
        cin >> si;
        iceCreamTypes[i].resize(si);
        for (int j = 0; j < si; j++) {
            cin >> iceCreamTypes[i][j];
            iceCreamTypes[i][j]--;
        }
        for (int j = 1; j < si; j++) {
            adjList[iceCreamTypes[i][j-1]].insert(iceCreamTypes[i][j]);
            adjList[iceCreamTypes[i][j]].insert(iceCreamTypes[i][j-1]);
        }
    }

    int maxColors = 0;
    vector<int> colors(m, 0);
    for (int i = 0; i < m; i++) {
        set<int> usedColors;
        for (int neighbor : adjList[i]) {
            usedColors.insert(colors[neighbor]);
        }
        for (int j = 1; j <= m+1; j++) {
            if (usedColors.find(j) == usedColors.end()) {
                colors[i] = j;
                maxColors = max(maxColors, j);
                break;
            }
        }
    }

    cout << maxColors << endl;
    for (int color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}