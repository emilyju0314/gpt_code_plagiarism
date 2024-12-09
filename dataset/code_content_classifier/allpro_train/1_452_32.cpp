#include <bits/stdc++.h>

#define ln                 '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

template<int mod> struct modulo {
	typedef modulo T;
	int w;
	operator int() const { return w; }
	
	modulo() {}
	modulo(int w) { this->w = w; fix(); }
	template<class type> modulo(type w) { this->w = w % mod; fix(); }
	void inline fix() { if (w >= mod || w < -mod) w %= mod; if (w < 0) w += mod; }
	
	inline T  operator -  () const { return mod - w; }
	inline T& operator += (const T &b) { if ((w += b.w) >= mod) w -= mod; return *this; }
	inline T& operator -= (const T &b) { if ((w -= b.w) < 0) w += mod; return *this; }
	inline T& operator *= (const T &b) { w = (unsigned long long) w * b.w % mod; return *this; }
	inline T& operator /= (const T &b) { return *this *= b.inv(); }
	#define make_operation(P)\
	friend inline T operator P (const T &a, const T &b) { return T(a) P##= b; }\
	template<class U> friend inline T operator P (const T &a, const U &b) { return T(a) P##= b; }\
	template<class U> friend inline T operator P (const U &a, const T &b) { return T(a) P##= b; }
	make_operation(+) make_operation(-) make_operation(*) make_operation(/)
	#undef make_operation
	
	T inline inv() const {
		int a = w, m = mod, u = 0, v = 1, t;
		for (; a != 0; t = m / a, m -= t * a, swap(a, m), u -= t * v, swap(u, v));
		return u;
	}
	
	friend inline T pow(const T &w, int p) {
		T a = w, r = 1; for (; p > 0; a *= a, p >>= 1) if (p & 1) r *= a; return r;
	}
};
const int mod = 998244353;
typedef modulo<mod> rem;

template<class A> struct matrix {
	typedef matrix T;
	int n, m;
	vector< vector<A> > d;
	
	matrix() {}
	matrix(int n, int m, int w = 0): n(n), m(m) {
		d.resize(n, vector<A>(m, 0));
		loop (i, min(n, m)) d[i][i] = w;
	}
	
	inline const vector<A>& operator [] (int id) const { return d[id]; }
	inline vector<A>& operator [] (int id) { return d[id]; }
	
	void inline set_size(int n, int m) {
		this->n = n, this->m = m;
		d.resize(n);
		loop (i, n) d[i].resize(m, 0);
	}
	
	inline T& operator *= (const T &b) { return *this = *this * b; }
	friend inline T operator * (const T &a, const T &b) {
		T r(a.n, b.m);
		loop (i, a.n) loop (k, a.m) if (a[i][k]) loop (j, b.m) if (b[k][j]) r[i][j] += a[i][k] * b[k][j];
		return r;
	}
	
	friend inline T pow(T a, int p) {
		T r(a.n, a.m, 1);
		for (; p; a *= a, p >>= 1) if (p & 1) r *= a;
		return r;
	}
};
typedef matrix<rem> mat;

const int nsz = 8, ndsz = 41, ssz = ndsz * ndsz, alpsz = 26;
int n, m, sz;
rem ans;
string s;
map< pair<int, int>, int> to;
mat T;

struct trie {
	bool ed[ndsz + 5];
	int rt, sz, g[ndsz + 5][alpsz + 5];
	
	trie() { rt = ++sz; }
	
	void inline ins(const string &s) {
		int u = rt;
		loop (i, s.size()) {
			int c = s[i] - 'a', &v = g[u][c];
			if (!v) v = ++sz;
			u = v;
		}
		ed[u] = 1;
	}
};
trie tr;

void inline init() {
	static pair<int, int> q[ssz + 5];
	int ql = 0, qr = 0;
	for (q[qr++] = {tr.rt, tr.rt}, to[{tr.rt, tr.rt}] = sz++; ql != qr;) {
		int u = q[ql].first, v = q[ql].second, w; ++ql;
		vector< pair<int, int> > to_u, to_v;
		loop (c, alpsz) if ((w = tr.g[u][c])) to_u.push_back({w, c});
		loop (c, alpsz) if ((w = tr.g[v][c])) to_v.push_back({w, c});
		if (tr.ed[u]) loop (c, alpsz) if ((w = tr.g[tr.rt][c])) to_u.push_back({w, c});
		if (tr.ed[v]) loop (c, alpsz) if ((w = tr.g[tr.rt][c])) to_v.push_back({w, c});
		for (auto p1 : to_u) for (auto p2 : to_v) if (p1.second == p2.second) {
			int w1 = p1.first, w2 = p2.first;
			if (!to[{w1, w2}]) {
				q[qr++] = {w1, w2}, to[{w1, w2}] = sz++;
				T.set_size(sz, sz);
			}
			T[to[{u, v}]][to[{w1, w2}]] += 1;
		}
	}
}

void inline solve() {
	mat R = pow(T, m);
	foreach (it, to) {
		int u = it->first.first, v = it->first.second;
		if (tr.ed[u] && tr.ed[v]) ans += R[0][it->second];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	cont (i, n) {
		cin >> s;
		tr.ins(s);
	}
	init();
	solve();
	printf("%d\n", ans.w);
}