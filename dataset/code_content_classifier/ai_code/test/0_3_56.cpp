#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

unordered_map<int, string> colors; // Map to store colors of special nodes
int k, n;
long long dp[2001][64][64][64]; // Dynamic programming table

bool isValid(int v, int u) {
    if (colors.find(v) != colors.end() && colors.find(u) != colors.end()) {
        string colorV = colors[v];
        string colorU = colors[u];
        
        if ((colorV == "white" && (colorU == "white" || colorU == "yellow")) ||
            (colorV == "yellow" && (colorU == "white" || colorU == "yellow")) ||
            (colorV == "green" && (colorU == "green" || colorU == "blue")) ||
            (colorV == "blue" && (colorU == "green" || colorU == "blue")) ||
            (colorV == "red" && (colorU == "red" || colorU == "orange")) ||
            (colorV == "orange" && (colorU == "red" || colorU == "orange"))) {
            return false;
        }
    }
    return true;
}

long long countColorings(int v, int level, int leftColor, int rightColor) {
    if (level == k) {
        return 1;
    }
    
    if (dp[v][level][leftColor][rightColor] != -1) {
        return dp[v][level][leftColor][rightColor];
    }
    
    long long ans = 0;
    int left = 2*v;
    int right = 2*v + 1;
    
    for (int i = 1; i <= 6; i++) {
        if (i != leftColor && i != rightColor) {
            ans = (ans + countColorings(left, level+1, rightColor, i) * countColorings(right, level+1, leftColor, i)) % MOD;
        }
    }
    
    return dp[v][level][leftColor][rightColor] = ans;
}

int main() {
    cin >> k >> n;
    
    for (int i = 0; i < n; i++) {
        int v;
        string color;
        cin >> v >> color;
        colors[v] = color;
    }
    
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 64; j++) {
            for (int l = 0; l < 64; l++) {
                for (int m = 0; m < 64; m++) {
                    dp[i][j][l][m] = -1;
                }
            }
        }
    }
    
    long long ans = countColorings(1, 1, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}