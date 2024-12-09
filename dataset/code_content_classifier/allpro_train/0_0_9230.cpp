#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> colors(n, 0);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = 0; j < i; j++) {
            if ((x1 == adj[j][0] && y1 < adj[j][3] && y2 > adj[j][1]) ||
                (x2 == adj[j][2] && y1 < adj[j][3] && y2 > adj[j][1]) ||
                (y1 == adj[j][1] && x1 < adj[j][2] && x2 > adj[j][0]) ||
                (y2 == adj[j][3] && x1 < adj[j][2] && x2 > adj[j][0])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        int used_colors[5] = {0};
        for (int j : adj[i]) {
            used_colors[colors[j]] = 1;
        }

        for (int j = 1; j <= 4; j++) {
            if (!used_colors[j]) {
                colors[i] = j;
                break;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << colors[i] << endl;
    }

    return 0;
}