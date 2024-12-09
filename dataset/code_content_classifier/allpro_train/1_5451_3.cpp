#include <bits/stdc++.h>
#define INF 1LL<<60
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

struct edge{
	int to,rev;
	ll cap,cost;
	edge(int t,int c,int co,int r){
		to=t;
		cap=c;
		cost=co;
		rev=r;
	}
};

struct mincostflow{
	vector<edge> G[2005];
	ll h[2005];
	ll dist[2005];
	int prevv[2005],preve[2005];

	void add_edge(int from,int to,int cap,int cost){
		G[from].push_back(edge(to,cap,cost,G[to].size()));
		G[to].push_back(edge(from,0,-cost,G[from].size()-1));
	}

	ll min_cost_flow(int s,int t,int f,int V){
		ll res=0;
		fill(h,h+V,0);
		while(f>0){
			priority_queue<P,vector<P>,greater<P> > que;
			fill(dist,dist+V,INF);
			dist[s]=0;
			que.push(P(0,s));
			while(que.size()){
				P p=que.top();
				que.pop();
				int v=p.second;
				if(dist[v]<p.first)continue;
				for(int i=0;i<G[v].size();i++){
					edge &e=G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to]=v;
						preve[e.to]=i;
						que.push(P(dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==INF)return -1;
			for(int v=0;v<V;v++){
				h[v]+=dist[v];
			}
			ll d=f;
			for(int v=t;v!=s;v=prevv[v]){
				d=min(d,G[prevv[v]][preve[v]].cap);
			}
			f-=d;
			res+=d*h[t];
			for(int v=t;v!=s;v=prevv[v]){
				edge &e=G[prevv[v]][preve[v]];
				e.cap-=d;
				G[v][e.rev].cap+=d;
			}
		}
		return res;
	}
};

mincostflow mi;
int cnt[1001];

int main(void){
	int n;
	scanf("%d",&n);
	ll res=0;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int t,c;
			scanf("%d%d",&t,&c);
			t--;
			mi.add_edge(i,t,50000,c);
			cnt[t]++;
			cnt[i]--;
			res+=c;
		}
	}
	int S=n,T=n+1;
	int fsum=0;
	for(int i=0;i<n;i++){
		if(cnt[i]>0){
			mi.add_edge(S,i,abs(cnt[i]),0);
		}else{
			mi.add_edge(i,T,abs(cnt[i]),0);
			fsum+=abs(cnt[i]);
		}
	}
	mi.add_edge(S,0,50000,0);
	res+=mi.min_cost_flow(S,T,fsum,T+1);
	printf("%lld\n",res);
	return 0;
}
