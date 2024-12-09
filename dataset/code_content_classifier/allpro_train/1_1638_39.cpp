#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MN = 55;

int d4[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool g[MN][MN][4];

bool can[MN][MN][4], canb[MN][MN][4];

int main() {
    int n, sx, sy, t;
    cin >> n >> sx >> sy >> t; sx++; sy++;
    for (int i = 0; i < n; i++) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by; ax++; ay++; bx++; by++;
        if (ax == bx) {
            if (ay > by) swap(ay, by);
            for (int j = ay; j < by; j++) {
                g[j][ax][0] = g[j+1][ax][2] = true;
            }
        } else {
            if (ax > bx) swap(ax, bx);
            for (int j = ax; j < bx; j++) {
                g[ay][j][1] = g[ay][j+1][3] = true;
            }
        }
    }
    string qu = "NESW";
    fill_n(can[sy][sx], 4, true);
    for (int i = 0; i < t; i++) {
        int di; char ty;
        cin >> di >> ty;
        int qd;
        for (int k = 0; k < 4; k++) {
            if (qu[k] == ty) {
                qd = k;
                break;
            }
        }
        for (int t = 0; t < di; t++) {
            fill_n(canb[0][0], MN*MN*4, false);
            for (int x = 0; x < MN; x++) {
                for (int y = 0; y < MN; y++) {
                    for (int d = 0; d < 4; d++) {
                        if (!g[y][x][d]) continue;
                        if (!can[y][x][d]) continue;
                        int yy = y+d4[d][0], xx = x+d4[d][1];
                        for (int nd = 0; nd < 4; nd++) {
                            if (d == (nd+2)%4) continue;
                            if (t == di-1 && d != qd && nd != qd) continue;
                            if (!g[yy][xx][nd]) continue;
                            canb[yy][xx][nd] = true;
                        }
                    }
                }
            }
            copy_n(canb[0][0], MN*MN*4, can[0][0]);
        }
    }

    for (int x = 0; x < MN; x++) {
        for (int y = 0; y < MN; y++) {
            for (int d = 0; d < 4; d++) {
                if (can[y][x][d]) {
                    printf("%d %d\n", x-1, y-1);
                    break;
                }
            }
        }
    }
    return 0;
}