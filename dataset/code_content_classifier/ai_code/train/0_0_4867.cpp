#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MOD 1000000007

using namespace std;

int dp[1005][1005];
int n;
vector<string> words;

int solve(int idx, int prev) {
    if(idx == n) return 1;
    
    int& ret = dp[idx][prev];
    if(ret != -1) return ret;
    
    ret = 0;
    // Delete char from current word
    for(int i = prev + 1; i <= words[idx].length(); i++) {
        if(words[idx][i] > words[idx][i-1]) {
            ret = (ret + solve(idx + 1, i)) % MOD;
        }
    }
    // Delete current word completely
    ret = (ret + solve(idx + 1, prev)) % MOD;
    
    return ret;
}

int main() {
    cin >> n;
    
    words.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0);
    cout << ans << endl;
    
    return 0;
}