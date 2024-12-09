#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

struct Cow{
	using D = int;
	const D inf = 1e9;
	struct Edge{
		int to;
		D cost;
		Edge(int to,D cost):to(to),cost(cost){}
	};
	int N,M;
	vector<vector<Edge>> G;
	vector<D> d;
	Cow(int N):N(N){
		G.assign(N,vector<Edge>());
		d.assign(N,inf);
	}
	void add_edge(int t,int s,D c){	// correspond to t-s <= c
//		printf("%d->%d   :%d\n",t,s,c);
		G[s].pb(Edge(t,c));
	}
	void add_edge(int t,int s,D clow,D chigh){	// clow <= t-s <= chigh
		add_edge(t,s,chigh);
		add_edge(s,t,-clow);
	}
	/*
		return the inequalities have a valid assignment
		if satisfiable, minimize d[T]-d[S]

		negative cycle    <=> unsatisfiable
		d[T] - d[S] = inf <=> feasible unboundedly

		d[S]=0

		T??????????????????????(?°???\???)
	*/
	bool IsValidAssign(int S = 0){
		vector<int> prev(N);
		d[S] = 0;
		rep(ph,N){
			bool update = 0;
			int v = -1;
			rep(s,N) for(auto e:G[s]){
				int t = e.to;
				D cost = e.cost;
				if(d[s]+cost < d[t]){
					update=1;
					v = t;
					d[t] = d[s]+cost;
					prev[t] = s;
				}
			}
			if(ph == N-1 && update){
				// vector<int> path;
				// path.pb(v);
				// int u = v;
				// do{
				// 	show(u);
				// 	u = prev[u];
				// 	path.pb(u);
				// }while(u!=v);
				// reverse(all(path));
				// show(path);
				// show(d[7]);
				// show(d[15]);
				return 0;
			}
			if(!update) break;
		}
		return 1;
	}
};

int W;
bool can(string s){
	int N = s.size();
	int V = N*2;
	Cow cow(V);
	rep(i,N){
		int clow = 0, chigh = 1;
		if(s[i]=='0') chigh = 0;
		if(s[i]=='1') clow = 1;
		cow.add_edge(i+N,i,clow,chigh);
		rep(t,2){
			int ni = (i*2+t)%N;
			cow.add_edge(ni,i+N,-t,-t);
		}
	}
	return cow.IsValidAssign();
}

string solve(){
	string s;
	cin>>W>>s;
	W = W*2+1;
	int N = s.size();
	if(can(s)) return s;
	int I = -1;
	for(int i=N-1;i>=0;i--){
		if(s[i]=='0'){
			s[i]='1';
			for(int j=i+1;j<N;j++) s[j]='*';
			if(can(s)){
				I = i;
				break;
			}
		}
	}
	if(I==-1) return "no";
	for(int i=I+1;i<N;i++){
		s[i]='0';
		if(can(s)) continue;
		else s[i]='1';
	}
	return s;
}
int main(){
	cout<<solve()<<endl;
}