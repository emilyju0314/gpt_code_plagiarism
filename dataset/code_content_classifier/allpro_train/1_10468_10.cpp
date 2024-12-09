#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1000000000;
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define rep(i,n) REP(i, 0, n)
typedef complex<double> P;

namespace std {
    bool operator < (const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

double cross(const P& a, const P& b) {
    return imag(conj(a) * b);
}

double dot(const P& a, const P& b) {
    return real(conj(a) * b);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c) > 0) return +1;
    if(cross(b, c) < 0) return -1;
    if(dot(b, c) < 0) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

const double EPS = 1.0e-11;
bool check(vector<P> l1, vector<P> l2) {
    int M = l1.size(), M2 = l2.size();
    if(M != M2) return false;
    rep(i, M - 1) {
        double d1 = norm(l1[i + 1] - l1[i]);
        double d2 = norm(l2[i + 1] - l2[i]);
        if(abs(d1 - d2) > EPS) return false;
    }
    rep(i, M - 2) {
        int c1 = ccw(l1[i], l1[i + 1], l1[i + 2]);
        int c2 = ccw(l2[i], l2[i + 1], l2[i + 2]);
        if(c1 != c2) return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    while(cin >> N && N) {
        vector<vector<P>> lines(N + 1);
        rep(i, N + 1) {
            int M; double x_, y_;
            cin >> M;
            rep(j, M) {
                cin >> x_ >> y_;
                lines[i].push_back(P(x_, y_));
            }
        }
        vector<P> rev = lines[0]; reverse(rev.begin(), rev.end());
        REP(i, 1, N + 1) {
            bool ok = false;
            ok |= check(lines[0], lines[i]);
            ok |= check(rev, lines[i]);
            if(ok) cout << i << endl;
        }
        cout << "+++++" << endl;
    }
    return 0;
}