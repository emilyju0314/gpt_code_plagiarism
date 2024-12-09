#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
const int UP = 1, DOWN = 0;
const int INF = 1 << 30;
int N, M;

vector<int> inv(vector<int> &a) {
    int sz = a.size();
    vector<int> ret(sz);
    for(int i=0; i<sz; i++) ret[i] = sz - a[i] + 1;
    return ret;
}

int calcrun(vector<int> &a) {
    int n = a.size();
    if(n == 1) return 1;
    else {
        int ret = 1;
        bool prev = (a[0] < a[1]);
        for(int i=2; i<n; i++) {
            ret += (prev != (a[i-1] < a[i]));
            prev = (a[i-1] < a[i]);
        }
        return ret;
    }
}

vector<int> getLis(vector<int> &p) {
    int n = p.size();
    vector<int> temp(n, INF);
    for(int i=0; i<n; i++) {
        int idx = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin();
        temp[ idx ] = p[i];
    }
    return temp;
}

int getLisSize(vector<int> p) {
    return lower_bound(p.begin(), p.end(), INF) - p.begin();
}

vector<pii> makevec(vector<int> &a, int r, bool needsort = false) {
    int n = a.size();
    vector<pii> ret;
    ret.push_back(pii(a[0], r));
    for(int i=1; i<n-1; i++) {
        if((a[i-1] < a[i]) != (a[i] < a[i+1])) {
            r++;
            ret.push_back(pii(a[i], -r));
        }
        else ret.push_back(pii(a[i], r));
    }
    ret.push_back(pii(a[n-1], r));
    if(needsort) sort(ret.begin(), ret.end(), greater<pii>());
    return ret;
}

// pattern, q
bool checkvecTwo(vector<pii> &a, vector<pii> &b, int mode) {
    int n = a.size(), m = b.size();
    int arr[] = {3, 2}, val = arr[mode];
    vector<int> s, t, x, y;
    for(int i=0; i<n; i++) {
        if(abs(a[i].second) < val) s.push_back(a[i].first);
        else if(a[i].second != -val) x.push_back(n - a[i].first + 1);
    }
    for(int i=0; i<m; i++) {
        if(abs(b[i].second) < val) t.push_back(b[i].first);
        else if(b[i].second != -val) y.push_back(m - b[i].first + 1);
    }
    int ns = getLisSize( getLis(s) );
    int nt = getLisSize( getLis(t) );
    int nx = getLisSize( getLis(x) );
    int ny = getLisSize( getLis(y) );
    return nt >= ns && ny >= nx;
}

// pattern, q
bool checkvecThree(vector<pii> &a, vector<pii> &b) {
    int n = a.size(), m = b.size(), cur = 0;
    vector<int> vp, vq;
    for(int i=0; i<n; i++) {
        vp.push_back(a[i].first);
        int type = a[i].second;
        while(1) {
            bool ok = false;
            if(b[cur].second == type) ok = true;
            if(type < 0 && b[cur].second > 0) {
                int t = type * (-1);
                if(b[cur].second == t || b[cur].second == t-1) ok = true;
            }
            if(b[cur].second < 0 && type > 0) {
                int t = b[cur].second * (-1);
                if(type == t || type == t-1) ok = true;
            }
            if(ok) {
                vq.push_back(b[cur].first);
                cur++; break;
            }
            if(++cur >= m) return false;
        }
    }
    return true;
}

bool solve_1(vector<int> &p, vector<int> &q) {
    int n = getLisSize( getLis(p) );
    int m = getLisSize( getLis(q) );
    return m >= n;
}

bool solve_2(vector<int> &p, vector<int> &q) {
    vector<pii> vp, vq;
    if(q[0] > q[1]) {
        vp = makevec(p, 2), vq = makevec(q, 1);
        return checkvecTwo(vp, vq, 0);
    }
    else {
        vp = makevec(p, 1), vq = makevec(q, 1);
        return checkvecTwo(vp, vq, 1);
    }
}

bool solve_3(vector<int> &p, vector<int> &q) {
    if(q[0] > q[1]) return false;
    vector<pii> vp, vq;
    vp = makevec(p, 1, true); vq = makevec(q, 1, true);
    return checkvecThree(vp, vq);
}

int main() {
    cin >> N;
    vector<int> q(N);
    for(int i=0; i<N; i++) scanf("%d", &q[i]);

    cin >> M;
    vector<int> pat(M);
    for(int i=0; i<M; i++) scanf("%d", &pat[i]);

    if(M > 1 && pat[0] > pat[1]) {
        q   = inv(q  );
        pat = inv(pat);
    }

    int RUN = calcrun(pat);
    if      (RUN == 1)  cout << (solve_1(pat, q) ? "Yes" : "No") << endl;
    else if (RUN == 2)  cout << (solve_2(pat, q) ? "Yes" : "No") << endl;
    else if (RUN == 3)  cout << (solve_3(pat, q) ? "Yes" : "No") << endl;
    else                cout << "No" << endl;
    return 0;
}