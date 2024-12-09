#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

namespace std{
	template<int N, class Tuple>size_t get_hash(const Tuple &t){
		return 0;
	}
	template<int N, class Tuple, class H, class ...Ts> size_t get_hash(const Tuple &t){
		return ((size_t)1e9+7)*hash<H>()(get<N>(t)) + get_hash<N+1,Tuple,Ts...>(t);
	}
	template<class ...Ts>struct hash<tuple<Ts...>>{
		size_t operator()(const tuple<Ts...>&t)const{
			return get_hash<0, tuple<Ts...>, Ts...>(t);
		}
	};
}

template<class T> inline int num(const unordered_map<T, int> &m, T k){
	auto it = m.find(k);
	if(it == m.end()) return 0;
	return it->second;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	vi v(n + m); rep(i, n + m) cin >> v[i];
	
	ll ans = 0;
	unordered_set<int> lens;
	unordered_map<int,int> cnt;
	unordered_map<pi,int> cnt2;
	unordered_set<tuple<int,int,int>> vis;
	rep(i, n){
		if(i < m){
			int a = v[i] - v[i + n], b = v[i + n];
			lens.insert(a);
			lens.insert(b);
			++cnt2[pi(min(a, b), max(a, b))];
		}
		else{
			++cnt[v[i]];
			lens.insert(v[i]);
		}
	}
	
	if(X == 0){
		vector<pi> vs;
		for(auto i : cnt) if(i.second >= 4) vs.emplace_back(i.first, i.second);
		rep(i, vs.size()){
			if(vs[i].second >= 12) ans++;
			if(vs[i].second >= 8) ans += (int)vs.size() - i - 1;
			for(int j = i + 1; j < vs.size(); j++){
				if(vs[j].second >= 8) ans++;
				ans += (int)vs.size() - j - 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	
	for(auto i : cnt2) for(int j : lens){
		vi l = {i.first.first, i.first.second, j};
		sort(all(l));
		
		if(vis.count(tie(l[0], l[1], l[2]))) continue;
		
		if(l[0] == l[1] && l[1] == l[2]){
			int x = min(X, num(cnt2, pi(l[0], l[1])));
			int y = num(cnt, l[0]);
			if(x == X && 2 * x + y >= 12) vis.emplace(l[0], l[1], l[2]);
		}
		else if(l[0] == l[1]){
			int x0 = min(X, num(cnt2, pi(l[0], l[1])));
			int x1 = min(X, num(cnt2, pi(l[0], l[2])));
			bool ok = 0;
			rep(i, x0+1){
				if(X - i > x1) continue;
				int a = 2 * i + X - i, c = X - i;
				if(a > 8 || c > 4) continue;
				if(a + num(cnt, l[0]) >= 8 &&
					c + num(cnt, l[2]) >= 4){
					ok = 1;
					break;
				}
			}
			if(ok) vis.emplace(l[0], l[1], l[2]);
		}
		else if(l[1] == l[2]){
			int x0 = min(X, num(cnt2, pi(l[0], l[1])));
			int x1 = min(X, num(cnt2, pi(l[1], l[2])));
			bool ok = 0;
			rep(i, x0+1){
				if(X - i > x1) continue;
				int a = i, c = i + 2*(X - i);
				if(a > 4 || c > 8) continue;
				if(a + num(cnt, l[0]) >= 4 &&
					c + num(cnt, l[2]) >= 8){
					ok = 1;
					break;
				}
			}
			if(ok) vis.emplace(l[0], l[1], l[2]);
		}
		else{
			int x0 = min(X, num(cnt2, pi(l[0], l[1])));
			int x1 = min(X, num(cnt2, pi(l[1], l[2])));
			int x2 = min(X, num(cnt2, pi(l[0], l[2])));
			bool ok = 0;
			rep(i, x0+1) rep(j, x1+1){
				if(X - i - j > x2 || i + j > X) continue;
				int a = i + (X - i - j), b = i + j, c = j + (X - i - j);
				if(a > 4 || b > 4 || c > 4) continue;
				if(a + num(cnt, l[0]) >= 4 &&
					b + num(cnt, l[1]) >= 4 &&
					c + num(cnt, l[2]) >= 4){
					ok = 1;
					break;
				}
			}
			if(ok) vis.emplace(l[0], l[1], l[2]);
		}
	}
	cout << vis.size() << endl;
	return 0;
}
