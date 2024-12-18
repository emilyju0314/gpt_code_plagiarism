#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Rectangle Union -- O(nlog(n)) (UNTESTED)
// WARNING: Does not do coordinate compression
// Finds the area of the union of axis-aligned rectangles
// Allows storing of prefix areas up to specific points, for prefix sums
// USAGE:
//  1. add_rect(x1,y1,x2,y2); with x1<x2 and y1<y2
//     This defines the rectangle [x1,x2] x [y1,y2]
//  2. add_query(l,r); with l<r. Query is for the area with l<x<r
//  3. solve(); to compute the areas, should only be called ONCE
//  4. query(l,r); to query
//*!
struct RectangleUnion {
    struct Segment {
        int a, b, v;
        Segment(): v(0) {}
        Segment(int a, int b, int v): a(a), b(b), v(v) {}
    };
    map<ll,vector<Segment>> segs;
    map<ll,int> cmpr;
    vector<ll> decmp;
    unordered_map<ll,ll> area;
    vector<ll> tag, cover, length;

    void add_rect(ll a, ll b, ll x, ll y) {
        segs[a].push_back(Segment(b,y,1));
        segs[x].push_back(Segment(b,y,-1));
        cmpr[b]; cmpr[y];
    }
    void add_query(ll a, ll b) {
        segs[a].push_back(Segment());
        segs[b].push_back(Segment());
    }
    ll query(ll a, ll b) {
        if (!area.count(a) || !area.count(b)) {
            throw runtime_error("query not added");
        }
        return area[b] - area[a];
    }

	int n;
    void setup() {
        int cnt = 0;
        vector<ll> len;
        for (auto it = cmpr.begin(); it != cmpr.end(); it++) {
            if (next(it) == cmpr.end()) len.push_back(0);
            else len.push_back(next(it)->first - it->first);
            decmp.push_back(it->first);
            it->second = cnt++;
        }
        n = 1 << (32 - __builtin_clz(cnt-1));
        tag.resize(2*n, 0);
        cover.resize(2*n, 0);
        length.resize(2*n, 0);
        for (int i = 0; i < cnt; i++) 
            length[i+n] = len[i];
        for (int i = n-1; i > 0; i--) 
            length[i] = length[2*i] + length[2*i+1];
    }

    void solve() {
        setup();
        ll cur = 0;
        ll pre = 0x5F3759DF;
        for (const pair<int,vector<Segment>>& it : segs) {
            cur += cover[1] * (it.first - pre);
            pre = it.first;

            for (const Segment& s : it.second) {
                if (s.v == 0) area[it.first] = cur;
                else update(cmpr[s.a], cmpr[s.b]-1, s.v, 1, 0, n-1);
            }
        }
    }

    void update(int l, int r, int v, int i, int s, int e) {
        if (e < l || r < s) return;
        if (l <= s && e <= r) {
            tag[i] += v;
        } else {
            int mid = (s+e)/2;
            update(l, r, v, 2*i, s, mid);
            update(l, r, v, 2*i+1, mid+1, e);
        }
        if (tag[i]) cover[i] = length[i];
        else if (i < n) cover[i] = cover[2*i] + cover[2*i+1];
        else cover[i] = 0;
    }
};
//*/

RectangleUnion ru;

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	int a, b, x, y;
	int minv = INF;
	int maxv = -INF;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> x >> y;
		ru.add_rect(a,b,x,y);
		minv = min(minv, a);
		maxv = max(maxv, x);
	}
	ru.add_query(minv, maxv);
	ru.solve();
	cout << ru.query(minv, maxv) << nl;

	return 0;
}
