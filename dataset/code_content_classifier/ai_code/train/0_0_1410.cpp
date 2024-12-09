#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    vector<int> dp(N+1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    int ans = dp[N];
    cout << ans << endl;

    return 0;
}