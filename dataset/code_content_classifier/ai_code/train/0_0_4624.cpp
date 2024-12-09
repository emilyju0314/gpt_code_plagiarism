#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int k;
vector<vector<int>> memo;

int dp(int i, int j) {
    if (i == -1) {
        return 1;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    int ans = (dp(i-1, j) + dp(i-1, j ^ (1 << i))) % MOD;
    memo[i][j] = ans;
    return ans;
}

int main() {
    cin >> k;
    int n = 0;
    while ((1 << n) <= k) {
        n++;
    }
    memo.assign(n, vector<int>(1 << n, -1));
    int result = dp(n-1, 0);
    cout << result << endl;
    return 0;
}