#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n, D;
vector<int> salaries[3001];
long long dp[3001][3001];

long long solve(int employee, int salary) {
    if (dp[employee][salary] != -1) {
        return dp[employee][salary];
    }
    
    long long ans = 0;
    for (int s : salaries[employee]) {
        if (s > salary) {
            break;
        }
        ans = (ans + solve(employee + 1, s)) % MOD;
    }
    
    return dp[employee][salary] = ans;
}

int main() {
    cin >> n >> D;
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        salaries[p].push_back(i);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= D; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 1; i <= D; i++) {
        dp[n][i] = 1;
    }
    
    long long ans = 0;
    for (int i = 1; i <= D; i++) {
        ans = (ans + solve(1, i)) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}