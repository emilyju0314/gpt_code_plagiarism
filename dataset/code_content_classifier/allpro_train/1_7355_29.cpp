#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<double, double> pd;
typedef pair<ll, ll> pl;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;

typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
const D EPS = 1e-9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

D dot(P a, P b) {
  return (conj(a)*b).X;
}

P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointLC(P a1, P a2, P c, D r) {
    VP ps;
    P ft = proj(a1, a2, c);
    if (!GE(r*r, norm(ft-c))) return ps;

    P dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
    return ps;
}

int n;
double x[50000], r[50000];

void solve() {
    rep(i,n) {
        cin >> x[i] >> r[i];
    }
    double le = 0.0, ri = 200000.0;
    rep(i,100) {
        double mid = (le + ri) / 2.0;
        P ho = P(0.0, mid), ge = P(1.0, mid);
        double nowl = -1000000.0, nowr = -1000000.0;
        bool ok = false;
        vector<pd> vd;
        rep(j,n) {
            VP vp = crosspointLC(ho, ge, P(x[j],0.0), r[j]);
            if (vp.size() != 2) continue;
            if (vp[0].X < vp[1].X) {
                vd.push_back(pd(vp[0].X, vp[1].X));
            } else {
                vd.push_back(pd(vp[1].X, vp[0].X));
            }
        }
        sort(vd.begin(), vd.end());
        rep(j,vd.size()) {
            if (nowr < vd[j].first) {
                nowl = vd[j].first;
                nowr = vd[j].second;
            } else {
                nowr = max(nowr, vd[j].second);
            }
            if (GE(nowr-nowl,2*mid)) {
                ok = true;
                break;
            }
        }
        if (ok) le = mid;
        else ri = mid;
    }
    printf("%.9f\n", le*2);
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
}

