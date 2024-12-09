#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int k, n;
vector<pair<int, string>> special_nodes;
long long dp[61][2001][64];

bool isValidColor(int mask, int node1, int node2) {
    if(node1 % 2 == 0 && (mask & 1 << 5)) return false; // White
    if(node1 % 2 == 1 && (mask & 1 << 4)) return false; // Yellow
    if(node1 % 4 == 0 && (mask & 1 << 3)) return false; // Green
    if(node1 % 4 == 1 && (mask & 1 << 2)) return false; // Blue
    if(node1 % 8 == 0 && (mask & 1 << 1)) return false; // Red
    if(node1 % 8 == 1 && (mask & 1 << 0)) return false; // Orange
    
    if(node2 % 2 == 0 && (mask & 1 << 5)) return false; // White
    if(node2 % 2 == 1 && (mask & 1 << 4)) return false; // Yellow
    if(node2 % 4 == 0 && (mask & 1 << 3)) return false; // Green
    if(node2 % 4 == 1 && (mask & 1 << 2)) return false; // Blue
    if(node2 % 8 == 0 && (mask & 1 << 1)) return false; // Red
    if(node2 % 8 == 1 && (mask & 1 << 0)) return false; // Orange
    
    return true;
}

long long solve(int level, int special_count, int mask) {
    if(level == k) return 1;
    if(dp[level][special_count][mask] != -1) return dp[level][special_count][mask];
    
    long long ans = 0;
    
    int left_node = (level + 1) * 2 - 1;
    int right_node = left_node + 1;
    
    // If no special node is colored at or above level, both colors are available
    if(special_count == 0) {
        for(int clr = 0; clr < 64; clr++) {
            if(isValidColor(clr, left_node, right_node)) {
                ans += solve(level+1, special_count, clr);
                ans %= MOD;
            }
        }
    } else {
        for(int clr = 0; clr < 64; clr++) {
            if(isValidColor(clr, left_node, right_node)) {
                bool valid = true;
                for(auto& special : special_nodes) {
                    if(special.first >= left_node && (clr & 1 << (special.second[0] - 'a'))) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    ans += solve(level+1, special_count, clr);
                    ans %= MOD;
                }
            }
        }
    }
    
    dp[level][special_count][mask] = ans;
    return ans;
}

int main() {
    cin >> k >> n;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n; i++) {
        int v;
        string s;
        cin >> v >> s;
        special_nodes.push_back({v, s});
    }
    
    int mask = 0;
    for(auto& special : special_nodes) {
        mask |= 1 << (special.second[0] - 'a');
    }
    
    cout << solve(0, n, mask) << endl;
    
    return 0;
}