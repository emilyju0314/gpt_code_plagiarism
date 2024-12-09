#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long double ldouble;

ldouble calc(int m, int n, int x) {
    // n / (m + n), m / (m + n)
    ldouble len[50][50] = {};
    len[0][0] = 1.0L; 
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= x; j++) {
            len[i + 1][j] = len[i][j] * n / (m + n);
            len[i][j + 1] = len[i][j] * m / (m + n);
        }
    }

    long long cnt[50][50] = {};
    cnt[0][0] = 1;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= x; j++){
            if(i > 0) cnt[i][j] += cnt[i - 1][j];
            if(j > 0) cnt[i][j] += cnt[i][j - 1];
            // printf("cnt[%d][%d] = %lld\n", i, j, cnt[i][j]);
        }
    }

    ldouble dist[50][50] = {};
    dist[0][0] = 0.0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= x; j++) {
            dist[i + 1][j] += dist[i][j];
            dist[i][j + 1] += dist[i][j] + len[i + 1][j] * cnt[i][j];
            // printf("dist[%d][%d] = %Lf\n", i, j, dist[i][j]);
        }
    }

    ldouble res = 0;
    for(int i = 0; i <= x; i++) {
        int j = x - i;
        // printf("i = %d : (%Lf + %Lf) * %Lf = %Lf\n", i, dist[i][j], len[i][j], len[i][j], (dist[i][j] + len[i][j]) * len[i][j]);
        res += (dist[i][j] + len[i][j] * cnt[i][j]) * len[i][j];
    }
    return res;
}

int main(){
    int m, n, x;
    int k, l, y;
    cin >> m >> n >> x;
    cin >> k >> l >> y;
    ldouble xsum = calc(m, n, x);
    ldouble ysum = calc(k, l, y);
    printf("%.12Lf\n", xsum * ysum);
    return 0;
}