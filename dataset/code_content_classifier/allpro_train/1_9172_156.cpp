#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
// typedef vector<int> V;
typedef vector<double> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    cin >> N >> M;
    VV v(N, V(3));
    rep(i, N) cin >> v[i][0] >> v[i][1] >> v[i][2];
    VV d(N, V(N, 0));
    rep(i, N) rep(j, N) rep(k, 3) {
        d[i][j] += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
    }

    double mx = -1;
    rep(s, 1 << N) {
        if (__builtin_popcount(s) != M) continue;

        double sm = 0;
        rep(i, N) {
            if ((s >> i) % 2 == 0) continue;
            rep(j, i) {
                if ((s >> j) % 2 == 0) continue;
                sm += d[i][j];
            }
        }
        mx = max(mx, sm);
    }

    printf("%.10f\n", mx);

}