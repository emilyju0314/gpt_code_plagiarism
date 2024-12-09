#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> pipes;
int minFuel = INF, maxCost = 0;

void dfs(int node, int flow, int cost) {
    if (node == n) {
        minFuel = min(minFuel, flow);
        maxCost = max(maxCost, cost);
        return;
    }

    for (int i = 0; i < n*(n-1)/2; i++) {
        if (pipes[i][0] == node) {
            if (flow + pipes[i][3] <= pipes[i][4]) {
                dfs(pipes[i][1], flow + pipes[i][3], cost + pipes[i][2] + pow(pipes[i][3], 2));
            }
        }
    }
}

int main() {
    cin >> n;
    pipes.resize(n*(n-1)/2);
    for (int i = 0; i < n*(n-1)/2; i++) {
        int s, f, l, h, a;
        cin >> s >> f >> l >> h >> a;
        pipes[i] = {s, f, l, h, a};
    }

    dfs(1, 0, 0);

    if (minFuel == INF || maxCost == 0) {
        cout << "-1 -1" << endl;
    } else {
        cout << minFuel << " " << maxCost << endl;
    }

    return 0;
}