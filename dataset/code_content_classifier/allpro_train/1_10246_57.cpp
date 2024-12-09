#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

int t;

const int mod = 998244353;
const int maxn = 3e5 + 5;
int dp[maxn];
int two_pows[maxn];

int prod(int a, int b) {
    return (a * b) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

int solve(vector<vector<char>>& a) {
    int n = a.size() - 1;
    int m = a[0].size() - 1;
    int totw = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            totw += (a[i][j] == 'o');
        }
    }
    // solve for each cont seq
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curl = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 'o' and a[i][j - 1] == 'o') {
                ans = add(ans, prod(dp[curl], two_pows[totw - curl]));
                curl = 0;
            } else if (a[i][j] == 'o') {
                curl++;
            }
        }
        if (a[i][m] == 'o') {
            ans = add(ans, prod(dp[curl], two_pows[totw - curl]));
        }
    }
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    two_pows[0] = 1;
    for (int i = 1; i < maxn; i++) {
        two_pows[i] = prod(two_pows[i - 1], 2);
    }
    for (int i = 2; i < maxn; i++) {
        // dp[i]: sum of maximum number of dominoes over a maximal contiguous sequence of the form "oooo" where 'o' occurs i times 
        // dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2] (1 + 2^(i-2))
        // Case 1: the ith elt is colored such that you cannot place a domino on it (contribution: dp[i - 1])
        // Case 2: the ith elt is colored to support the domino, but the (i-1)th element is different (contribution: dp[i - 2])
        // Case 3: the ith elt and the (i-1)th elt are colored to support the domino (contribution: dp[i - 2] + 2^(i-2))
        dp[i] = add(dp[i - 1], dp[i - 2]);
        dp[i] = add(dp[i], add(dp[i - 2], two_pows[i - 2]));
    }
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        string st; cin >> st;
        for (int j = 1; j <= m; j++) {
            a[i][j] = st[j - 1];
        }
    }
    int ans1 = solve(a);
    // transpose
    vector<vector<char>> b(m + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[j][i] = a[i][j];
        }
    }
    int ans2 = solve(b);
    int ans = add(ans1, ans2);
    cout << ans << "\n";
} 