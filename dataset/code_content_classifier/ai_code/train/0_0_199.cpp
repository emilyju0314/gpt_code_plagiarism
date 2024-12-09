#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> table;
vector<vector<vector<int>>> dp;

int calculate(int r, int c, int mask) {
    if (r == n-1 && c == n-1) {
        return 0;
    }
    if (dp[r][c][mask] != -1) {
        return dp[r][c][mask];
    }
    
    int next_r = r, next_c = c;
    if ((mask & 1) == 0) {
        next_c = min(n-1, c+1);
    } else {
        next_r = min(n-1, r+1);
    }
    
    int ans = 0;
    if ((next_r + next_c - r - c) % 2 == 1) {
        ans = 1e9;
    }
    
    if (next_r < n && next_c < n) {
        int new_mask = 0;
        if (table[next_r][next_c] == 'a') {
            new_mask |= 1;
        }
        if (table[next_r][next_c] == 'b') {
            new_mask |= 2;
        }
        ans = max(ans, calculate(next_r, next_c, new_mask) + (mask == 0 && new_mask == 3));
    }
    
    if ((mask & 2) == 0) {
        next_r = min(n-1, r+1);
    } else {
        next_c = min(n-1, c+1);
    }
    
    if (next_r < n && next_c < n) {
        int new_mask = 0;
        if (table[next_r][next_c] == 'a') {
            new_mask |= 1;
        }
        if (table[next_r][next_c] == 'b') {
            new_mask |= 2;
        }
        ans = max(ans, calculate(next_r, next_c, new_mask) + (mask == 0 && new_mask == 3));
    }
    
    return dp[r][c][mask] = ans;
}

int main() {
    cin >> n;
    table.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }
    
    dp.assign(n, vector<vector<int>>(n, vector<int>(4, -1)));
    
    int result = calculate(0, 0, 0);
    
    if (result > 0) {
        cout << "FIRST" << endl;
    } else if (result < 0) {
        cout << "SECOND" << endl;
    } else {
        cout << "DRAW" << endl;
    }
    
    return 0;
}