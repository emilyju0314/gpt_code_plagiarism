#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <random>
//cin.sync_with_stdio(false);
//streambuf
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
template<class T, int s>using va = vector<array<T, s>>;
template<class T, class T2> using umap = unordered_map<T, T2>;
template<class T> using uset = unordered_set<T>;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define ALL(a) a.begin(),a.end()
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a) for(int i=1;i<=a;i++)
#define rrep(i,a) for(int i=(a)-1;i>=0;i--)
#define rrep1(i,a) for(int i=a;i;i--)
const ll mod = 1000000007;
#define REP rep
template<class T>using heap = priority_queue<T, vector<T>, greater<T>>;
template<class T>using pque = priority_queue<T, vector<T>, function<T(T, T)>>;
template <class T>
inline void hash_combine(size_t & seed, const T & v) {
	hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
	template<typename S, typename T> struct hash<pair<S, T>> {
		inline size_t operator()(const pair<S, T> & v) const {
			size_t seed = 0;
			hash_combine(seed, v.first);
			hash_combine(seed, v.second);
			return seed;
		}
	};
	// Recursive template code derived from Matthieu M.
	template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
	struct HashValueImpl {
		static void apply(size_t& seed, Tuple const& tuple) {
			HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
			hash_combine(seed, std::get<Index>(tuple));
		}
	};
	template <class Tuple>
	struct HashValueImpl<Tuple, 0> {
		static void apply(size_t& seed, Tuple const& tuple) {
			hash_combine(seed, std::get<0>(tuple));
		}
	};
	template <typename ... TT>
	struct hash<std::tuple<TT...>> {
		size_t operator()(std::tuple<TT...> const& tt) const {
			size_t seed = 0;
			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);
			return seed;
		}
	};
}
template<class T>int id(vector<T> &a, T b) {
	return lower_bound(ALL(a), b) - a.begin();
}
ll pow(ll base, ll i, ll mod) {
	ll a = 1;
	while (i) {
		if (i & 1) {
			a *= base;
			a %= mod;
		}
		base *= base;
		base %= mod;
		i /= 2;
	}
	return a;
}
ll gcd(ll a, ll b) {
	while (b) {
		ll c = a%b;
		a = b;
		b = c;
	}
	return a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}
int popcnt(unsigned long long a) {
	a = (a & 0x5555555555555555) + (a >> 1 & 0x5555555555555555);
	a = (a & 0x3333333333333333) + (a >> 2 & 0x3333333333333333);
	a = (a & 0x0f0f0f0f0f0f0f0f) + (a >> 4 & 0x0f0f0f0f0f0f0f0f);
	a = (a & 0x00ff00ff00ff00ff) + (a >> 8 & 0x00ff00ff00ff00ff);
	a = (a & 0x0000ffff0000ffff) + (a >> 16 & 0x0000ffff0000ffff);
	return (a & 0xffffffff) + (a >> 32);
}
class unionfind {
	vector<int> par, rank, size_;//????????§??????????????¢???????????????????????????rank???????????????size?????????
public:
	unionfind(int n) :par(n), rank(n), size_(n, 1) {
		iota(ALL(par), 0);
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])swap(x, y);
		par[y] = x;
		size_[x] += size_[y];
		if (rank[x] == rank[y])rank[x]++;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return size_[find(x)];
	}
};
template<class T, class Func = function<T(T, T)>>
class segtree {
	vector<T> obj;
	int offset;
	Func updater;
	T e;
	int bufsize(int num) {
		int i = 1;
		for (; num >i; i <<= 1);
		offset = i - 1;
		return (i << 1) - 1;
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return e;
		if (a <= l && r <= b)return obj[k];
		else return updater(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
	}
	/*
	template<class QF = function<T(T, T)>>
	auto query(int a, int b, int k, int l, int r,QF qf) {
	if (r <= a || b <= l)return e;
	if (a <= l && r <= b)return obj[k];
	else return qf(query(a, b, k * 2 + 1, l, (l + r) / 2, qf), query(a, b, k * 2 + 2, (l + r) / 2, r, qf));
	}*/
public:
	T query(int a, int b) {//[a,b)
		return query(a, b, 0, 0, offset + 1);
	}/*
	 template<class QF = function<T(T, T)>>
	 auto query(int a, int b,QF &&qf) {//[a,b)
	 return query(a, b, 0, 0, offset + 1,qf);
	 }*/
	void updateall(int l = 0, int r = -1) {
		if (r < 0)r = offset + 1;
		l += offset, r += offset;
		do {
			l = l - 1 >> 1, r = r - 1 >> 1;
			for (int i = l; i < r; i++)obj[i] = updater(obj[i * 2 + 1], obj[i * 2 + 2]);
		} while (l);
	}
	void update(int k, T &a) {
		k += offset;
		obj[k] = a;
		while (k) {
			k = k - 1 >> 1;
			obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);
		}
	}
	segtree(int n, T e, const Func &updater = Func()) :obj(bufsize(n), e), e(e), updater(updater) {}
	segtree(vector<T> &vec, T e, const Func &updater = Func()) :obj(bufsize(vec.size()), e), e(e), updater(updater) {
		copy(vec.begin(), vec.end(), obj.begin() + offset);
		updateall();
	}
	typename vector<T>::reference operator[](int n) {
		return obj[n + offset];
	}
};
template<class T = int>
class BIT {//????¬????BIT????????????????????????????????°??????????????????
	vector<T> bit;
	int n;
public:
	BIT(int n) :bit(n + 1, 0) {}
	void add(int i, T x) {
		i++;
		while (i <= n) {
			bit[i] += x;
			i += i&-i;
		}
	}
	T sum(int i) {
		T s = 0;
		i++;
		while (i) {
			s += bit[i];
			i &= i - 1;
		}
		return s;
	}
};
template<class T = int>
class rangeadd {
	BIT<T> b0, b1;
public:
	rangeadd(int n) :b0(n), b1(n) {};
	void add(int l, int r, T x) {//[l,r)
		b0.add(l, -x*(l - 1));
		b1.add(l, x);
		b0.add(r, x*r);
		b1.add(r, -x);
	}
	T sum(int i) {
		if (i < 0)return 0;
		return b0.sum(i) + b1.sum(i)*i;
	}
	T sum(int l, int r) {
		return sum(r - 1) - sum(l - 1);
	}
};
//end of lib
int main() {
	int n, m;
	while (cin >> n >> m, n) {
		unionfind uf(n);
		int g = 0;
		rep(i, m) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			if (!uf.same(a, b)) {
				g++;
				uf.unite(a, b);
			}
		}
		if (g == 0)cout << pow(2, n, mod) << endl;
		else if (g == n - 1)cout << 3 << endl;
		else cout << (pow(2, n - g, mod) + 1) % mod << endl;
	}
}