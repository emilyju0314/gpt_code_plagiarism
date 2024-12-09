#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 500;
int dp[MAX_N][MAX_N][2]; // dp[i][j][k] represents the minimum energy wasted to reach cell (i, j) with k representing if the cell is killed

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int> > > transformers(N+M-1); // store transformers based on starting time

    for(int i = 0; i < K; i++) {
        int x, y, d, t, e;
        cin >> x >> y >> d >> t >> e;
        
        transformers[t].push_back({x, y});
        transformers[(t+d) % (N+M-1)].push_back({x+d, y-d});
        transformers[(t+2*d) % (N+M-1)].push_back({x+d, y});
        transformers[(t+3*d) % (N+M-1)].push_back({x, y+d});
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    for(int t = 0; t < N+M-1; t++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                // Not killed
                if(dp[i][j][0] != -1) {
                    for(auto& transformer : transformers[t]) {
                        int x = transformer.first;
                        int y = transformer.second;
                        if(x == i && y == j) {
                            dp[i][j][1] = max(dp[i][j][1], dp[i][j][0]);
                        }
                    }
                }
                // Right
                if(i+1 < N) {
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0]);
                    dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][1]);
                }
                // Down
                if(j+1 < M) {
                    dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][0]);
                    dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][1]);
                }
            }
        }
    }

    cout << max(dp[N-1][M-1][0], dp[N-1][M-1][1]) << endl;

    return 0;
}