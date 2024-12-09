#include <bits/stdc++.h>
typedef std::pair<int, int> pii;
using namespace std;

int const INF = 1 << 30;
int const INIT = 1 << 28;
int n;
vector<pii> a, b, c;
vector<int> p;

bool d(int x) {
    vector<pii> q, r, s;
    int qq[] = {x, 0, 0};
    int rr[] = {0, x, 0};
    int ss[] = {0, 0, x};
    for(int i=0; i<3; i++) {
        vector<pii> result(n);
        for(int j=0; j<n; j++) result[j] = make_pair(0, j);
        q = a, r = b, s = c;
        q[0].first += qq[i];
        r[0].first += rr[i];
        s[0].first += ss[i];

        sort(q.begin(), q.end(), greater<pii>());
        sort(r.begin(), r.end(), greater<pii>());
        sort(s.begin(), s.end(), greater<pii>());
        int sq = INF, sr = INF, ss = INF;
        int gq = -1, gr = -1, gs = -1;
        for(int j=0; j<n; j++) {
            int nq = q[j].first;
            int nr = r[j].first;
            int ns = s[j].first;
            if(nq < sq) sq = nq, gq = j;
            if(nr < sr) sr = nr, gr = j;
            if(ns < ss) ss = ns, gs = j;
            result[q[j].second].first += p[gq];
            result[r[j].second].first += p[gr];
            result[s[j].second].first += p[gs];
        }
        sort(result.begin(), result.end(), greater<pii>());
        int rank = -1;
        int temp = INF, idx = -1;
        for(int j=0; j<n; j++) {
            int cur = result[j].first;
            if(cur < temp) temp = cur, idx = j;
            if(result[j].second == 0) rank = idx+1;
        }
        if(rank < 9) return true;
    }
    return false;
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    p.resize(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) {
        int x, y, z; cin >> x >> y >> z;
        a[i] = make_pair(x, i);
        b[i] = make_pair(y, i);
        c[i] = make_pair(z, i);
    }
    int ub = INIT, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(d(mid)) ub = mid;
        else lb = mid;
    }
    if(ub < INIT) cout << ub << endl;
    else cout << "Saiko" << endl;
    return 0;
}