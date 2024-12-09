#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, K, D, S;
    cin >> N >> M >> K >> D >> S;

    vector<vector<pair<int, int>>> customers(N+1);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        customers[c].push_back({a, b});
    }

    vector<vector<int>> dp(N+1, vector<int>(K+1, 1e9));
    dp[0][0] = S;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            if(dp[i][j] == 1e9) continue;
            int t = dp[i][j];
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(auto& c : customers[i]) {
                int a = c.first, b = c.second;
                if(a <= t) {
                    pq.push({t+b, b});
                } else {
                    pq.push({a+b, b});
                }
            }

            while(!pq.empty() && j < K) {
                auto [nt, nb] = pq.top();
                pq.pop();
                dp[i][j+1] = min(dp[i][j+1], nt + D);
                t = nt + D;
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i <= K; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}