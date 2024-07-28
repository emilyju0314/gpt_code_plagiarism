#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int n;
int L;
int cuts[55];
int dp[55][55];

int solve(int left, int right) {
    if (left + 1 == right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;
    for (int i = left + 1; i < right; i++) {
        ans = min(ans, solve(left, i) + solve(i, right) + cuts[right] - cuts[left]);
    }
    
    return dp[left][right] = ans;
}

int main() {
    while (cin >> L && L) {
        cin >> n;
        
        cuts[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> cuts[i];
        }
        cuts[n+1] = L;

        memset(dp, -1, sizeof(dp));

        int result = solve(0, n+1);
        cout << "The minimum cutting is " << result << "." << endl;
    }

    return 0;
}
