#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 5005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n;
long long dp[MAXN][MAXN][2];
pair<int, int> v[MAXN];

bool Comp(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v + 1, v + n + 1, Comp);

    for(int l = 0; l <= n; ++l) {
        for(int r = 0; l + r <= n; ++r) {
            for(int c = 0; c <= 1 && l + r + c <= n; ++c) {
                if(l == 0 && r == 0 && c == 0) continue;

                int L = v[l + r + c].first;
                int R = v[l + r + c].second;
                int X = L + R;

                dp[l][r][c] = INF;
                if(l > 0)
                    dp[l][r][c] = min(dp[l][r][c], dp[l - 1][r][c] + R + 1LL * (l - 1) * X);
                if(r > 0)
                    dp[l][r][c] = min(dp[l][r][c], dp[l][r - 1][c] + L + 1LL * (r - 1) * X);
                if(c > 0)
                    dp[l][r][c] = min(dp[l][r][c], dp[l][r][c - 1] + 1LL * n / 2 * X);
            }
        }
    }


    printf("%lld\n", ((n % 2) ? dp[n / 2][n / 2][1] : dp[n / 2][n / 2][0]));

    return 0;
}