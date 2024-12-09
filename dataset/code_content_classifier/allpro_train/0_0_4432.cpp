#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2, m, r, b;
    cin >> n1 >> n2 >> m >> r >> b;

    string colors1, colors2;
    cin >> colors1 >> colors2;

    vector<int> redCount1(n1, 0);
    vector<int> blueCount1(n1, 0);
    vector<int> redCount2(n2, 0);
    vector<int> blueCount2(n2, 0);

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        if (colors1[u-1] == 'R') redCount1[u-1]++;
        if (colors1[u-1] == 'B') blueCount1[u-1]++;
        if (colors2[v-1] == 'R') redCount2[v-1]++;
        if (colors2[v-1] == 'B') blueCount2[v-1]++;
    }

    int totalCost = 0;
    string result = "";

    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        if (colors1[u-1] == 'R' && redCount1[u-1] <= blueCount1[u-1]) {
            cout << -1 << endl;
            return 0;
        }

        if (colors1[u-1] == 'B' && blueCount1[u-1] <= redCount1[u-1]) {
            cout << -1 << endl;
            return 0;
        }

        if (colors2[v-1] == 'R' && redCount2[v-1] <= blueCount2[v-1]) {
            cout << -1 << endl;
            return 0;
        }

        if (colors2[v-1] == 'B' && blueCount2[v-1] <= redCount2[v-1]) {
            cout << -1 << endl;
            return 0;
        }

        if (colors1[u-1] == 'U' && colors2[v-1] == 'U') {
            result += "U";
        } else if (colors1[u-1] != colors2[v-1]) {
            if (colors1[u-1] == 'R' && colors2[v-1] == 'B') {
                totalCost += b;
                result += "B";
            } else {
                totalCost += r;
                result += "R";
            }
        } else {
            result += "U";
        }
    }

    cout << totalCost << endl;
    cout << result << endl;

    return 0;
}