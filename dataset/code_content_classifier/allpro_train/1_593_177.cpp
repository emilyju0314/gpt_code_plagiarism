#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = ll(1e9) + 7;
const ll INF = LLONG_MAX;
const ll MAX_N = 1 << 12;
const double EPS = 10e-8;
const double PI = 3.14159265359;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)

int main() {
    while (1) {
        int h, w, e[11][11];
        cin >> h >> w;
        if (h == 0) break;
        REP(i, h) {
            REP(j, w) { cin >> e[i][j]; }
        }
        int ans = 0;
        REP(it, h) {
            FOR(ib, it + 2, h) {
                REP(jl, w) {
                    FOR(jr, jl + 2, w) {
                        int hmin = 10;
                        FOR(i, it, ib+1) hmin = min(hmin, min(e[i][jl], e[i][jr]));
                        FOR(j, jl, jr+1) hmin = min(hmin, min(e[it][j], e[ib][j]));
                        bool flag = true;
                        int p = 0;
                        FOR(i, it + 1, ib && flag) {
                            FOR(j, jl + 1, jr && flag) {
                                if (e[i][j] >= hmin) {
                                    flag = false;
                                    break;
                                }
                                p += hmin - e[i][j];
                            }
                        }
                        if (flag) ans = max(ans, p);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

