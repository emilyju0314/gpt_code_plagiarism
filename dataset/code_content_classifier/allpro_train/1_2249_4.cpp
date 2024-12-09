#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 210;

struct MT {
    int n;
    bool g[MN][MN];
    int mt[MN];
};

vector<int> findMwalk(MT mt) {
    int n = mt.n;
    bool used[MN][2] = {};
    int back[MN][2];
    for (int st = 0; st < n; st++) {
        if (mt.mt[st] != -1) continue;
        if (used[st][0]) continue;
        using P = pair<int, int>;
        queue<P> q;
        q.push(P(st, 0));
        used[st][0] = true;
        while (!q.empty()) {
            int a; int ty;
            tie(a, ty) = q.front(); q.pop();
            int b = mt.mt[a];
            if (b == -1 and ty == 1) {
                int now = a, nt = 1;
                vector<int> v;
                while (now != st or nt != 0) {
                    v.push_back(now);
                    now = back[now][nt];
                    nt = 1-nt;
                }
                v.push_back(st);
                return v;
            }

            if (ty == 0) {
                for (int j = 0; j < n; j++) {
                    if (!mt.g[a][j]) continue;
                    assert(a != j);
                    if (used[j][1]) continue;
                    used[j][1] = true;
                    back[j][1] = a;
                    q.push(P(j, 1));
                }
            } else {
                if (used[b][0] == false) {
                    used[b][0] = true;
                    back[b][0] = a;
                    q.push(P(b, 0));
                }
            }
        }
    }
    return vector<int>();
}

bool maxmt(MT &mt) {
    int n = mt.n;

    // printf("deb\n");
    // printf("mt\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d, ", mt.mt[i]);
    // }
    // printf("\n");
    // printf("g\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", mt.g[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    auto v = findMwalk(mt);
    if (v.size() == 0) return false;

    int m = (int)v.size();
    int ok[MN];
    fill_n(ok, MN, -1);
    for (int i = 0; i < m; i++) {
        int d = v[i];
        if (ok[d] != -1) {
            int l = ok[d], r = i;
            MT nmt = mt;
            for (int idx = l+1; idx < r; idx++) {
                int j = v[idx];
                //nmt clear
                for (int k = 0; k < n; k++) {
                    if (nmt.g[j][k] and d != k) {
                        nmt.g[d][k] = true;
                        nmt.g[k][d] = true;
                    }
                    nmt.g[j][k] = nmt.g[k][j] = false;
                }
                nmt.mt[j] = -1;
            }
            bool f = maxmt(nmt);

            if (!f) return false;
            copy_n(nmt.mt, MN, mt.mt);
            int e = mt.mt[d];
            if (e == -1) return true;
            mt.mt[d] = mt.mt[e] = -1;
            for (int idx = l; idx < r; idx++) {
                int j = v[idx];
                if (!mt.g[e][j]) continue;
                mt.mt[e] = j;
                mt.mt[j] = e;
                rotate(v.begin()+l, v.begin()+idx, v.begin()+r);
                assert((r - (l+1)) % 2 == 0);
                for (int k = l+1; k < r; k += 2) {
                    mt.mt[v[k]] = v[k+1];
                    mt.mt[v[k+1]] = v[k];
                }
                return true;
            }
            assert(false);
        }
        ok[d] = i;
    }
    for (int i = 0; i < m; i += 2) {
        mt.mt[v[i]] = v[i+1];
        mt.mt[v[i+1]] = v[i];
    }
    return true;
}

MT first;
int solve() {
    int co = 0;
    while (maxmt(first)) {
//        printf("*************END************\n");
        co++;
    }
    return co;
}



int main() {
    memset(first.g, 0, sizeof(first.g));
    memset(first.mt, -1, sizeof(first.mt));
    int n, m;
    cin >> n >> m; n--;
    first.n = n;
    bool one[MN] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 1) {
            one[b-2] = true;
        } else {
            a -= 2; b -= 2;
            first.g[a][b] = first.g[b][a] = true;
        }
    }
    solve();
    for (int i = 0; i < n; i++) {
        if (first.mt[i] == -1) {
            printf("No\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!one[i]) continue;
        first.g[i][n] = first.g[n][i] = true;
    }
    first.n++;
    auto v = findMwalk(first);
    if (v.size() == 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}