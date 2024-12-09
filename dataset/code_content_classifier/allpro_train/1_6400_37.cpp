# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)

using Flow = LL;
using Cost = LL;
const int MAX_V = 100000;
 
struct PrimalDual {
	struct Edge {
		LL d, c, f, w, r, is_r;
		Edge(LL d_, LL c_, LL f_, LL w_, LL r_, bool is_r_)
			: d(d_), c(c_), f(f_), w(w_), r(r_), is_r(is_r_) {}
	};
	LL n;
	vector<vector<Edge>> g;
	PrimalDual(LL n_) : n(n_), g(vector<vector<Edge> >(n_)) {}
	void add_edge(LL src, LL dst, LL cap, LL cost) {  // 有向辺
		LL rsrc = g[dst].size();
		LL rdst = g[src].size();
		g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
		g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
	}
	LL solve(LL s, LL t, LL f) {
		LL res = 0;
		static LL h[100000 + 10], dist[100000];
		static LL prevv[100000 + 10], preve[100000 + 10];
		priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>> > q;
		fill(h, h + n, 0);
		while (f > 0) {
			fill(dist, dist + n, HINF<LL>());
			dist[s] = 0;
			q.emplace(0, s);
			while (q.size()) {
				LL cd;
				LL v;
				tie(cd, v) = q.top();
				q.pop();
				if (dist[v] < cd) continue;
				for (LL i = 0; i < (LL)(g[v].size()); ++i) {
					Edge &e = g[v][i];
					if (residue(e) == 0) continue;
					if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
						dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
						prevv[e.d] = v;
						preve[e.d] = i;
						q.emplace(dist[e.d], e.d);
					}
				}
			}
			if (dist[t] == HINF<LL>()) return -1;  // 経路が見つからなかった
			// s-t 間最短路に沿って目一杯流す
			for (LL i = 0; i < n; ++i) h[i] += dist[i];
			LL d = f;
			for (LL v = t; v != s; v = prevv[v]) {
				d = min(d, residue(g[prevv[v]][preve[v]]));
			}
			f -= d;
			res += d * h[t];
			for (LL v = t; v != s; v = prevv[v]) {
				Edge &e = g[prevv[v]][preve[v]];
				e.f += d;
				g[v][e.r].f -= d;
			}
		}
		return res;
	}
	LL residue(const Edge &e) { return e.c - e.f; }
};

int n;
int a[1010], b[1010];
vector<int> v;
map<int, int> mp;
int main(){
	cin >> n;
	REP(i, n){
		cin >> a[i] >> b[i];
		v.emplace_back(a[i]);
		v.emplace_back(b[i]);
	}
	sort(ALL(v));
	UNIQUE(v);
	REP(i, (int)v.size()){
		mp[v[i]] = i;
	}
	int st = (int)v.size() + n;
	int go = (int)v.size() + n + 1;
	PrimalDual pd(2 + (int)v.size() + n);
	REP(i, (int)v.size()){
		pd.add_edge(st, i, 1, 0);
	}
	REP(i, n){
		pd.add_edge(mp[a[i]], (int)v.size() + i, 1, -b[i]);
		pd.add_edge(mp[b[i]], (int)v.size() + i, 1, -a[i]);
		pd.add_edge((int)v.size() + i, go, 1, 0);
	}
	pd.add_edge(st, go, HINF<LL>(), 0);
	cout << -pd.solve(st, go, n) << endl;
}
