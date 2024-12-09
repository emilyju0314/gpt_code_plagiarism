#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

#define MOD 1000000007

using namespace std;

int k, n;
map<int, string> colors;
int dp[2001][64];

bool isValid(int parent, string parentColor, string childColor) {
    if ((parentColor == "white" && (childColor == "white" || childColor == "yellow")) ||
        (parentColor == "yellow" && (childColor == "white" || childColor == "yellow")) ||
        (parentColor == "green" && (childColor == "green" || childColor == "blue")) ||
        (parentColor == "blue" && (childColor == "green" || childColor == "blue")) ||
        (parentColor == "red" && (childColor == "red" || childColor == "orange")) ||
        (parentColor == "orange" && (childColor == "red" || childColor == "orange"))) {
        return false;
    }
    return true;
}

int countColorings(int node, int level) {
    if (colors.find(node) != colors.end()) {
        string nodeColor = colors[node];
        int valid = 1;
        for (int i = 0; i < level; i++) {
            valid = (valid * 6) % MOD;
        }
        return valid;
    }

    if (dp[node][level] != -1) {
        return dp[node][level];
    }

    int ans = 0;
    ans = (ans + countColorings(2*node, level-1) * countColorings(2*node+1, level-1)) % MOD;

    for (int i = 1; i < level; i++) {
        ans = (ans + countColorings(2*node, i-1) * countColorings(2*node+1, level-i-1)) % MOD;
        ans = (ans + countColorings(2*node+1, i-1) * countColorings(2*node, level-i-1)) % MOD;
    }

    dp[node][level] = ans;
    return ans;
}

int main() {
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int node;
        string color;
        cin >> node >> color;
        colors[node] = color;
    }

    memset(dp, -1, sizeof(dp));

    int result = countColorings(1, k);
    cout << result << endl;

    return 0;
}