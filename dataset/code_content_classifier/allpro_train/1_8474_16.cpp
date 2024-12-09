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
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const double EPS = 1e-8, INF = 1e12, PI = acos(-1.0);
typedef complex<double> P;
namespace std{
	bool operator<(const P& a, const P& b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
inline double cross(const P& a, const P& b){ return imag(conj(a)*b); }
inline double dot(const P& a, const P& b){ return real(conj(a)*b); }
struct L : public vector<P>{
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
typedef vector<P> G;
inline int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if(cross(b, c) >  EPS)   return +1;      // counter clockwise
	if(cross(b, c) < -EPS)   return -1;      // clockwise
	if(dot(b, c)   < -EPS)   return +2;      // c--a--b on line
	if(norm(b)+EPS <norm(c)) return -2;      // a--b--c on line
	return 0;                                   // c is between a and b (inclusive)
}
G isCC(P c1, double r1, P c2, double r2){
	double x = norm(c1 - c2);
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if(d < -EPS) return vector<P>(0);
	if(d < 0) d = 0;
	P q1 = c1 + (c2 - c1) * y, q2 = (c2 - c1) * sqrt(d) * P(0, 1);
	G res;
	res.pb(q1 - q2); res.pb(q1 + q2);
	return res;
}

vector<pi> input(){
	int n; cin >> n;
	
	vector<pi> in, res;
	rep(i, n){
		int x, r; cin >> x >> r;
		in.emplace_back(x + r, -x + r);
	}
	sort(all(in)); in.erase(unique(all(in)), in.end());
	n = in.size();
	
	int left = -1e9;
	rep(i, n){
		int l = -in[i].second, r = in[i].first;
		if(l > left) res.emplace_back((l + r) / 2, (r - l) / 2);
		left = max(left, l);
	}
	return res;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	vector<pi> in = input();
	int n = in.size();
	
	//rep(i, n) dbg(in[i]);
	auto getY = [&](double x, int id){
		//y^2 + (x - x0)^2 = r^2
		return sqrt(pow(in[id].second, 2.0) - pow(x - in[id].first, 2.0));
	};
	
	vector<pair<double, int>> cs;
	cs.emplace_back(in[n - 1].first - in[n - 1].second, n - 1);
	for(int i = n - 2; i >= 0; i--){
		int lo = 0, hi = cs.size(), mid;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			if(cs[mid].first > in[i].first + in[i].second ||
				getY(cs[mid].first, cs[mid].second) > getY(cs[mid].first, i) + EPS) hi = mid;
			else lo = mid;
		}
		int id = cs[lo].second;
		G c = isCC(P(in[id].first, 0), in[id].second, P(in[i].first, 0), in[i].second);
		
		if(c.empty()){
			cout << 0 << endl;
			return 0;
		}
		
		cs.erase(cs.begin() + hi, cs.end());
		cs.emplace_back(real(c[0]), i);
		
		//dbg(i, hi); rep(j, cs.size()) dbg(cs[j]);
	}
	
	double ans = 0;
	rep(i, cs.size()){
		double l = cs[i].first;
		double r = i==cs.size()-1 ? in[cs[i].second].first + in[cs[i].second].second : cs[i + 1].first;
		
		if(l - EPS < in[cs[i].second].first && in[cs[i].second].first < r + EPS)
		ans = max(ans, (double)in[cs[i].second].second);
		else ans = max(ans, getY(l, cs[i].second));
	}
	printf("%.20f\n", ans);
	
	return 0;
}
