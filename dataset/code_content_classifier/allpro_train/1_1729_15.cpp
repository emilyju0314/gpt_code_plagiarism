#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// ?????°???????????¨(RMQ ??????)
// update: k ??????????????? a ????????´
// query: [l, r) ?????????????????§???????±???????
template<typename T>
struct ST {
    vector<T> seg;
    int size;
    ST(int n) {
        size = 1;
        while (size < n) size *= 2;
        seg.resize(2*size-1, numeric_limits<T>::min());
    }
    inline T merge(T x, T y) {
        return max(x, y);
    }
    void update(int k, T a) {
        k += size-1;
        seg[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            seg[k] = merge(seg[k*2+1], seg[k*2+2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return numeric_limits<T>::min();
        if (a <= l && r <= b) return seg[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return merge(vl, vr);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, size);
    }
};

// Euler-Tour
const int MAXSIZE = 200020;
int BEGIN[MAXSIZE], END[MAXSIZE];
vector<int> euler_tour;
int K;

struct edge {
    int to;
    int cost;
    edge() {}
    edge(int to, int cost) : to(to), cost(cost) {}
};

vector<vector<edge> > G;

void createEulerTour(int v, int p) {
    BEGIN[v] = K++;
    euler_tour.push_back(v);
    for (edge e : G[v]) {
        if (e.to == p) continue;
        createEulerTour(e.to, v);
        euler_tour.push_back(v);
        K++;
    }
    END[v] = K;
}

typedef pair<int, int> Result;
Result visit(int p, int v, const vector<vector<edge> >& g) {
    Result r(0, v);
    for (edge e : g[v]) if (e.to != p) {
        Result t = visit(v, e.to, g);
        t.first += e.cost;
        if (r.first < t.first) r = t;
    }
    return r;
}

// ??´???????§????????????????????????? (u, v) ?????????
pii diameter(const vector<vector<edge> >& g) {
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return pii(r.second, t.second);
}

void dfs(int v, int p, int d, vi& depth) {
    depth[v] = d;
    for (edge e : G[v]) if (e.to != p) {
        dfs(e.to, v, d+e.cost, depth);
    }
}

int calc(int s) {
    int n = G.size();
    vector<int> depth(n);
    dfs(s, -1, 0, depth);
    euler_tour.clear();
    K = 0;
    createEulerTour(s, -1);
    ST<int> seg(2*n);
    for (int i = 0; i < n; i++) seg.update(BEGIN[i], depth[i]);
    int ret = 0;
    for (int v = 0; v < n; v++) {
        for (edge e : G[v]) {
            int tmp = max(seg.query(0, BEGIN[e.to]), seg.query(END[e.to], 2*n));
            ret = max(ret, tmp+e.cost);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    G.resize(N);
    for (int i = 1; i < N; i++) {
        int p, w;
        cin >> p >> w;
        G[i].emplace_back(p, w);
        G[p].emplace_back(i, w);
    }
    pii dia = diameter(G);
    cout << max(calc(dia.first), calc(dia.second)) << endl;
    return 0;
}