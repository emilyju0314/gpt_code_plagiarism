#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 577;
const ll INF = LLONG_MAX / 2;

int N;
ll A[MAX_N][MAX_N], cost1[MAX_N][MAX_N], cost2[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            scanf("%lld", &A[i][j]);
            if (i < j) cost1[i][j] = A[i][j];
            else cost2[j][i] = A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cost1[i][j] += cost1[i][j - 1];
        }
    }
    for (int i = N; i; i--) {
        for (int j = 1; j <= N; j++) {
            cost1[i][j] += cost1[i + 1][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = N; j; j--) {
            cost2[i][j] += cost2[i][j + 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cost2[i][j] += cost2[i - 1][j];
        }
    }
    for (int i = 1; i < N; i++) {
        dp[0][i] = cost1[1][i];
        for (int j = 1; j < i; j++) {
            dp[j][i] = INF;
            for (int k = 0; k < j; k++) {
                dp[j][i] = min(dp[j][i], dp[k][j] + cost1[j + 1][i] + cost2[j][i + 1] - cost2[k][i + 1]);
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            ans = min(ans, dp[j][i] + cost1[i + 1][N]);
        }
    }
    printf("%lld\n", ans);
}
