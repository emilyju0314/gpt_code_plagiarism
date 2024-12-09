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

const int dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};
int n, m;
string in[100];
bool v[50][50];

void rec(int y, int x){
	v[y][x] = 1;
	rep(d, 4){
		int ny = y + dy[d], nx = x + dx[d];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(v[ny][nx] || in[ny][nx] == '#') continue;
		rec(ny, nx);
	}
}
bool con_check(){
	memset(v, 0, sizeof(v));
	rec(0, 0);
	return v[0][m - 1] && v[n - 1][0] && v[n - 1][m - 1];
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	while(cin >> n >> m, n){
		rep(i, n) cin >> in[i];
		
		bool found = 0;
		if(!con_check()){
			found = 1;
			goto END;
		}
		rep(y, n) rep(x, m) if(in[y][x] == '.'){
			if(y==0 && x==0 || y==0 && x==m-1 || y==n-1 && x==0 || y==n-1 && x==m-1) continue;
			in[y][x] = '#';
			if(!con_check()){ found = 1; goto END; }
			in[y][x] = '.';
		}
		END:
		cout << (found ? "NO" : "YES") << endl;
	}
	return 0;
}