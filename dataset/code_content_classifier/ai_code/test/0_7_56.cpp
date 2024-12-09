#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

#define MOD 1000000007

using namespace std;

unordered_map<string, int> colorToInt;
unordered_map<int, string> intToColor;
vector<int> adj[2002];
int dp[2002][6];

int getColorInt(string color) {
    return colorToInt[color];
}

void buildGraph(int node, int parent) {
    for (int child : adj[node]) {
        if (child == parent) continue;
        buildGraph(child, node);
    }
}

int main() {
    colorToInt["white"] = 0;
    colorToInt["yellow"] = 1;
    colorToInt["green"] = 2;
    colorToInt["blue"] = 3;
    colorToInt["red"] = 4;
    colorToInt["orange"] = 5;

    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        string color;
        cin >> v >> color;
        int colorInt = getColorInt(color);
        adj[v].push_back(colorInt);
        adj[colorInt].push_back(v);
    }

    buildGraph(1, -1);
    
    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;

    for (int i = 1; i <= (1 << k) - 1; i++) {
        for (int j = 0; j < 6; j++) {
            for (int child : adj[i]) {
                dp[i][j] = (dp[i][j] + dp[child][(j + 1) % 6] + dp[child][(j + 5) % 6]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans = (ans + dp[1][i]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}