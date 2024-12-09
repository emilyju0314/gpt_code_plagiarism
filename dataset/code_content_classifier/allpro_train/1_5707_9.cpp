#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;
using ull = unsigned long long;

using R = long double;
using P = complex<R>;


const R EPS = 1e-10;
const R PI = acos((R)(-1));

int sgn(R a) {
    if (a < -EPS) return -1;
    if (a > EPS) return 1;
    return 0;
}

int sgn(R a, R b) {
    return sgn(b-a);
}
bool near(const P &a, const P &b) {
    return !sgn(abs(a-b));
}

R cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
R dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }
int ccw(P a, P b, P c) {
    assert(!near(a, b));
    if (near(a, c) || near(b, c)) return 0;
    int s = sgn(cross(b-a, c-a));
    if (s) return s;
    if (dot(b-a, c-a) < 0) return 2;
    if (dot(a-b, c-b) < 0) return -2;
    return 0;
}

struct L {
    P x, y;
    L() {}
    L(P x, P y) : x(x), y(y) {}
};

bool same(L a, L b) {
    if (ccw(b.x, b.y, a.x) % 2) return false;
    if (ccw(b.x, b.y, a.y) % 2) return false;
    return true;
}

template<int N>
struct SUnionFind {
    int i2g[N];
    SUnionFind() {
        for (int i = 0; i < N; i++) {
            i2g[i] = i;
        }
    }
    SUnionFind(ull hs) {
        for (int i = 0; i < N; i++) {
            i2g[i] = hs & 0xf;
            hs >>= 4;
        }
    }

    void merge(int x, int y) {
        int xg = i2g[x], yg = i2g[y];
        for (int i = 0; i < N; i++) {
            if (i2g[i] == yg) i2g[i] = xg;
        }
    }

    bool same(int x, int y) {
        return i2g[x] == i2g[y];
    }

    ull uf2hash() {
        int b[N];
        memset(b, -1, sizeof(b));
        int c = 0;
        ull hs = 0;
        for (int i = N-1; i >= 0; i--) {
            hs <<= 4;
            if (b[i2g[i]] == -1) {
                b[i2g[i]] = c;
                c++;
            }
            hs += b[i2g[i]];
        }
        return hs;
    }
};

const int MN = 8;
using Pi = pair<int, int>;
using UF = SUnionFind<MN>;

int n;
P p[MN];


vector<vector<Pi>> idlist;
map<ull, int> dp;
int solve(ull hs) {
//    printf("solve %lld\n", hs);
    UF uf(hs);
    {
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (!uf.same(0, i)) {
                f = false;
            }
        }
        if (f) return 0;
    }
    if (dp.count(hs)) {
        return dp[hs];
    }
    int ans = 100000;
    for (vector<Pi> lis: idlist) {
        bool f = false;
        UF uf2(hs);
        for (Pi p: lis) {
            if (uf2.same(p.first, p.second)) continue;
            f = true;
            uf2.merge(p.first, p.second);
        }
        if (!f) continue;
        ans = min(ans, 1+solve(uf2.uf2hash()));
    }
    return dp[hs] = ans;
}

int main2() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = P(x, y);
    }
    vector<L> v;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            L q = L(
                (p[i]+p[j])*(R)0.5,
                (p[i]+p[j])*(R)0.5 + polar<R>(1, arg(p[i]-p[j])+PI/2)
            );
            v.push_back(q);
        }
    }
    for (L l: v) {
        vector<Pi> lis;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                L q = L(
                    (p[i]+p[j])*(R)0.5,
                    (p[i]+p[j])*(R)0.5 + polar<R>(1, arg(p[i]-p[j])+PI/2)
                );
                if (same(l, q)) {
                    lis.push_back(Pi(i, j));
                }
            }
        }
/*        printf("list\n");
        for (Pi pi: lis) {
            printf("(%d, %d), ", pi.first, pi.second);
        }
        printf("\n");*/
        idlist.push_back(lis);
    }
    sort(idlist.begin(), idlist.end());
    idlist.erase(unique(idlist.begin(), idlist.end()), idlist.end());
    printf("%d\n", solve(UF().uf2hash()));
    return 0;
}

int main() {
    static ll eord, enew;
    const int sz = 256*1024*1024;
    static unsigned char *p = (unsigned char*)malloc(sz);
    enew = ((ll)(p+sz-1) & ~0xff);
    __asm__ volatile("mov %%rsp, %0" : "=r"(eord));
    __asm__ volatile("mov %0, %%rsp" : : "r"(enew));
    main2();
    __asm__ volatile("mov %0, %%rsp" : : "r"(eord));
    return 0;
}