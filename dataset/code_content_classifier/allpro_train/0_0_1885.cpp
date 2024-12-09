#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXC = 30;
const int INF = 1e9;

int N, C;
int D[MAXC][MAXC];
int c[MAXN][MAXN];
int dp[MAXN][MAXC];

int main() {
    cin >> N >> C;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXC; j++) {
            dp[i][j] = INF;
        }
    }

    for(int j = 0; j < C; j++) {
        dp[0][j] = 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < C; k++) {
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + D[j][k]);
            }
        }
    }

    int ans = INF;
    for(int j = 0; j < C; j++) {
        for(int k = 0; k < C; k++) {
            int sum = 0;
            for(int i = 0; i < N; i++) {
                sum += D[c[i][0]][j];
            }
            for(int i = 0; i < N; i++) {
                sum = min(sum, sum - D[c[i][0]][j] + D[c[i][0]][k]);
                ans = min(ans, sum + dp[N-1][k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}