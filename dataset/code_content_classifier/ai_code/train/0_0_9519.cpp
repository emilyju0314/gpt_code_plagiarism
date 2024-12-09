#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_NODES = 40;
const int MAX_ARROWS = 400;
const int INF = 1e9;

struct Arrow {
    int from, to;
    string label;
};

int n, a, s, g;
vector<Arrow> arrows;
string mostPowerfulSpell;
bool visited[MAX_NODES];
int dist[MAX_NODES][MAX_NODES][7];

bool dfs(int node, const string& spell) {
    if (node == g) {
        if (mostPowerfulSpell.empty() || spell < mostPowerfulSpell) {
            mostPowerfulSpell = spell;
        }
        return true;
    }

    visited[node] = true;
    for (Arrow& arrow : arrows) {
        if (arrow.from == node && !visited[arrow.to]) {
            string nextSpell = spell + arrow.label;
            if (nextSpell.size() > 6) {
                continue;
            }
            if (mostPowerfulSpell.empty() || nextSpell < mostPowerfulSpell) {
                dfs(arrow.to, nextSpell);
            }
        }
    }
    visited[node] = false;

    return false;
}

int main() {
    while (true) {
        cin >> n >> a >> s >> g;
        if (n == 0 && a == 0 && s == 0 && g == 0) break;

        arrows.clear();
        mostPowerfulSpell.clear();

        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 7; k++) {
                    dist[i][j][k] = INF;
                }
            }
        }

        for (int i = 0; i < a; i++) {
            int from, to;
            string label;
            cin >> from >> to >> label;
            arrows.push_back({from, to, label});
        }

        dfs(s, "");

        if (mostPowerfulSpell.empty()) {
            cout << "NO" << endl;
        } else {
            cout << mostPowerfulSpell << endl;
        }
    }

    return 0;
}