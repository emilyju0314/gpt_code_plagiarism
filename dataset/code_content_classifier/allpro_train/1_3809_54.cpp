#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


//#define int ll

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
vector<int> a, b;
int dp[2][3][60][60][60][60];
int suma[60][60];
int sumb[60][60];
int dfs(int c, int d, int e, int f, int g, int h) {
    if (d == 3) return 0;
    if (dp[c][d][e][f][g][h] != -1e9) return dp[c][d][e][f][g][h];
    int now = suma[e][f] - sumb[g][h]; // set it to "pass"
    now += dfs((c + 1) % 2, d + 1, f, f, h, h);
    if (c == 0) {
        if (f != a.size()) {
            if (a[f] != -1) {
                now = max(now, dfs(1, 0, e, f + 1, g, h));
            }
            else {
                now = max(now, dfs(1, 0, e, f + 1, h, h));
            }
        }
    }
    else {
        if (h != b.size()) {
            if (b[h] != -1) {
                now = min(now, dfs(0, 0, e, f, g, h + 1));
            }
            else {
                now = min(now, dfs(0, 0, f, f, g, h + 1));
            }
        }
    }
    return dp[c][d][e][f][g][h] = now;
}
void solve() {
    int n, m;
    cin >> n >> m;
    REP(i, n) {
        int c;
        cin >> c;
        a.push_back(c);
    }
    REP(i, m) {
        int c;
        cin >> c;
        b.push_back(c);
    }
    REP(i, n) {
        int geko = 0;
        for (int q = i; q < n; ++q) {
            geko += max(0, a[q]);
            suma[i][q + 1] = geko;
        }
    }
    REP(i, m) {
        int geko = 0;
        for (int q = i; q < m; ++q) {
            geko += max(0, b[q]);
            sumb[i][q + 1] = geko;
        }
    }
    REP(i, 2) {
        REP(q, 3) {
            REP(j, 60) {
                REP(j2, 60) {
                    REP(j3, 60) {
                        REP(j4, 60) {
                            dp[i][q][j][j2][j3][j4] = -1e9;
                        }
                    }
                }
            }
        }
    }
    cout << dfs(0, 0, 0, 0, 0, 0) << endl;
}

#undef int
int main() {
    init();
    solve();
}
