#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> d(N);
    for(int i = 0; i < N; i++) {
        cin >> d[i];
    }

    vector<vector<int>> dp(N, vector<int>(R+1, 0));

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= R; j++) {
            dp[i][j] = d[i];
        }
    }

    vector<vector<int>> adj(N, vector<int>(N, 1000000000));

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for(int j = 1; j <= R; j++) {
        for(int i = 1; i < N; i++) {
            for(int k = 0; k < i; k++) {
                if(j >= adj[k][i]) {
                    dp[i][j] = max(dp[i][j], dp[k][j-adj[k][i]] + d[i]);
                }
            }
        }
    }

    int max_balls = 0;
    for(int j = 0; j <= R; j++) {
        max_balls = max(max_balls, dp[N-1][j]);
    }

    cout << max_balls << endl;

    return 0;
}