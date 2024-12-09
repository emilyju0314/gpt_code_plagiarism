#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define INF (1<<29)
#define MAX_V 202

struct edge{
	int to,cap,cost,rev;
	edge(int a,int b,int c,int d):to(a),cap(b),cost(c),rev(d){}
};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	while(f>0){
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update){
			update=false;
			for(int v=0;v<V;v++){
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();i++){
					edge &e=G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=true;
					}
				}
			}
		}
		if(dist[t]==INF)return -1;
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int main(){
	int n,p[100];
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++){
		add_edge(0,1+i,1,0);
		add_edge(1+n+i,1+2*n,1,0);
		for(int j=0;j<n;j++){
			if(p[i]!=j+1){
				add_edge(1+i,n+1+j,1,p[i]*abs(i-j));
			}
		}
	}
	V=2*n+2;
	cout<<min_cost_flow(0,1+2*n,n)<<endl;
	return 0;
}