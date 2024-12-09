#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i=0;i<n;++i)
#define MP make_pair
#define PB push_back

typedef double DB;
typedef long long LL;

const DB EPS = 1e-8;
const DB PI = acos(-1);
const DB gg = 9.8;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;


inline void checkMin(int &a, int b){
    if (b < a) a = b;
}

inline int sgn(double x){
    return x < -EPS ? -1 : x > EPS;
}

const int N = int(1e2) + 9;
int n, l[N], b[N], r[N], t[N];
int X, Y; DB V; int low;

inline DB y(DB a, DB x) {
    DB t = x/(V*cos(a));
    return V*sin(a)*t - 0.5*gg*t*t;
}

inline DB getM(DB a){
    DB t = V*sin(a)/gg;
    return V*cos(a)*t;
}

bool ck(DB a) {

    DB h = y(a, X); if (sgn(h-Y) < 0 || sgn(h-low) > 0 ) return false;
    DB mx = getM(a), my = y(a, mx);

    REP(i, n){

        DB h1 = y(a, l[i]), h2 = y(a, r[i]);

        if (l[i] <= mx && mx <= r[i]){
            if (!(h1 <= b[i] && h2 <= b[i] && my <= b[i] || h1 >= t[i] && h2 >= t[i] && my >= t[i])) return false;
        }
        else{
            if (!(h1 <= b[i] && h2 <= b[i] || h1 >= t[i] && h2 >= t[i])) return false;
        }
    }
    return true;
}

bool ck() {

    REP(i, n){
        if (l[i] == 0 && b[i] == 0) return false;
        if (l[i] <= X && X <= r[i]  && b[i] <= Y && Y <= t[i]) return false;
    }

    DB d = PI/2/10000;
    for (DB a=d;a<=PI/2;a+=d) if (ck(a)) return true;
    return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%lf%d%d", &n, &V, &X, &Y)) {
        low = INF; REP(i, n){
            scanf("%d%d%d%d", &l[i], &b[i], &r[i], &t[i]);
            if (l[i] > X){
                --i; --n;
                continue;
            }
            if (r[i] >= X){
                if (b[i] >= Y) checkMin(low, b[i]);
                r[i] = X;
            }
        }
        puts(ck() ? "Yes" : "No");
    }
}