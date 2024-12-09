#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
#define MOD 1000000007
using namespace std;

unordered_map<string, int> colorToInt;
int n, k;
int dp[2001][6][6];
bool visited[2001];
vector<int> adj[2001];

int color(string s) {
    if(colorToInt.find(s) != colorToInt.end()) {
        return colorToInt[s];
    } else {
        return 0;
    }
}

int dfs(int node, int parent, int color1, int color2) {
    if(dp[node][color1][color2] != -1) {
        return dp[node][color1][color2];
    }

    int res = 1;
    for(int neighbor : adj[node]) {
        if(neighbor == parent || visited[neighbor]) {
            continue;
        }
        for(int c1 = 0; c1 < 6; c1++) {
            for(int c2 = 0; c2 < 6; c2++) {
                if((c1 == color1 && c2 == color2) ||
                   (c1 == color2 && c2 == color1)) {
                    continue;
                }
                res = (res * dfs(neighbor, node, c1, c2)) % MOD;
            }
        }
    }

    return dp[node][color1][color2] = res;
}

int main() {
    colorToInt["white"] = 1;
    colorToInt["yellow"] = 2;
    colorToInt["green"] = 3;
    colorToInt["blue"] = 4;
    colorToInt["red"] = 5;
    colorToInt["orange"] = 6;

    cin >> k >> n;

    int totalNodes = (1 << k) - 1;
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        int v;
        string s;
        cin >> v >> s;
        visited[v] = true;
        dp[v][color(s)][color(s)] = 0;
    }

    for(int i = 1; i < totalNodes; i++) {
        int u = i;
        int v = (i << 1);
        adj[u].push_back(v);
        adj[v].push_back(u);

        v++;
        if(v <= totalNodes) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int res = 0;
    for(int c1 = 0; c1 < 6; c1++) {
        for(int c2 = 0; c2 < 6; c2++) {
            if(c1 != c2) {
                res = (res + dfs(1, 0, c1, c2)) % MOD;
            }
        }
    }

    cout << res << endl;

    return 0;
}