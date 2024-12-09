#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M, K;

    while (true) {
        cin >> N >> M >> K;

        if (N == 0 && M == 0 && K == 0) {
            break;
        }

        vector<pair<pair<int, int>, pair<int, int>>> warpHoles;
        for (int i = 0; i < K; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            warpHoles.push_back({{a, b}, {c, d}});
        }

        vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, 0));
        dp[1][1] = 1;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
                
                for (auto hole : warpHoles) {
                    int ai = hole.first.first;
                    int bi = hole.first.second;
                    int ci = hole.second.first;
                    int di = hole.second.second;
                    
                    if (ai <= i && i <= ci && bi <= j && j <= di) {
                        dp[i][j] = (dp[i][j] - dp[ai][bi] + dp[ai][bi] + MOD) % MOD;
                    }
                }
            }
        }

        cout << dp[N][M] << endl;
    }

    return 0;
}