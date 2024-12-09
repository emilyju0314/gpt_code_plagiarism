#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

double dp[1 << 6][50][50];

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }
    
    dp[0][0][0] = 1.0;
    
    for(int mask = 0; mask < (1 << N); mask++) {
        for(int i = 0; i <= C; i++) {
            for(int j = 0; j <= C; j++) {
                if(dp[mask][i][j] == 0.0) continue;
                for(int k = 0; k < N; k++) {
                    if(mask & (1 << k)) continue;
                    
                    int ni = min(C, i + L[k]);
                    int nj = min(C, j + L[k]);
                    
                    dp[mask | (1 << k)][ni][nj] += dp[mask][i][j] / C;
                }
            }
        }
    }
    
    double ans = 0.0;
    for(int i = 0; i <= C; i++) {
        for(int j = 0; j <= C; j++) {
            if(i + j < C) continue;
            ans += dp[(1 << N) - 1][i][j];
        }
    }
    
    cout << fixed << setprecision(15) << ans << endl;
    
    return 0;
}