#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1<<30;
const int EPS = 1e-8;
#define PB push_back
#define mk make_pair
#define fi first
#define se second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int > Pii;
class edge{
	public:
	int to;
	int cost;
	edge(){}
	edge(int _to,int _cost){
		to = _to;
		cost = _cost;
	}
	bool operator<(const edge &a)const{
		return cost>=a.cost;
	}
};
vector < edge > G[3002];
int path[3002];
int N,M,K;
void dijkstra(int s[3002]){

	priority_queue<edge> Q;
	rep(i,K){
		Q.push(edge(s[i],0));
	}
	while(!Q.empty()){
		edge e = Q.top();
		Q.pop();
		if(path[e.to] < INF)continue;
		path[e.to] = e.cost;
		rep(i,G[e.to].size()){
			Q.push(edge(G[e.to][i].to,G[e.to][i].cost+e.cost));
		}
	}
	return ;
}
int main(){
	scanf("%d%d%d",&N,&M,&K);
	fill(path,path+N,INF);
	rep(i,M){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		G[a].PB(edge(b,c));
		G[b].PB(edge(a,c));
	}
	int s[3002];
	rep(i,K){
		int tmp;
		scanf("%d",&tmp);
		s[i] = --tmp;
	}
	dijkstra(s);
	double ans = 0;
	rep(i,N){
		rep(j,G[i].size()){
			int d = path[G[i][j].to]-path[i];
			if(d<0.0)continue;
			double g = path[i]+d+(G[i][j].cost-d)/2.0;
			ans = max(g,ans);
		}
	}
	printf("%.0lf\n",round(ans));
	return 0;
}