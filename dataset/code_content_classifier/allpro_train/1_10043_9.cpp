#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

const ll INF=1LL<<61;

struct edge{
	int v;
	ll cost;
	int type; // 0: normal edge, 1: magical edge
};

struct point{ double x,y; };

// y=a1*x+b1, y=a2*x+b2 の交点
point crosspoint(ll a1,ll b1,ll a2,ll b2){
	double x=(double)(b2-b1)/(a1-a2);
	double y=a1*x+b1;
	return (point){x,y};
}

// y = 0*x+d[0]
// y = 1*x+d[1]
// y = 2*x+d[2]
//   :
// y = k*x+d[k]
// で定まる下側エンベロープの x での値を求める
ll eval(int k,const ll *d,ll x){
	ll res=INF;
	rep(i,k+1) res=min(res,i*x+d[i]);
	return res;
}

int main(){
	for(int n,m,s1,s2,t;scanf("%d%d%d%d%d",&n,&m,&s1,&s2,&t),n;){
		s1--; s2--; t--;
		vector<edge> G[1000];
		int k=0; // magical edge の本数
		rep(i,m){
			int u,v;
			char cost[16]; scanf("%d%d%s",&u,&v,cost); u--; v--;
			if(cost[0]!='x'){
				int c=atoi(cost);
				G[u].push_back((edge){v,c,0});
				G[v].push_back((edge){u,c,0});
			}
			else{
				G[u].push_back((edge){v,0,1});
				G[v].push_back((edge){u,0,1});
				k++;
			}
		}

		static ll d[1000][101];
		rep(u,n) rep(i,k+1) d[u][i]=INF;
		d[t][0]=0;
		priority_queue< pair< ll,pair<int,int> > > Q; Q.push(make_pair(0,make_pair(t,0)));
		while(!Q.empty()){
			ll d_now=-Q.top().first;
			int u=Q.top().second.first,i=Q.top().second.second; Q.pop();

			if(d_now>d[u][i]) continue;

			rep(j,G[u].size()){
				int v=G[u][j].v,type=G[u][j].type;
				ll cost=G[u][j].cost;
				int i2=i+type;
				if(i2<=k && d[v][i2]>d[u][i]+cost){
					d[v][i2]=d[u][i]+cost;
					Q.push(make_pair(-d[v][i2],make_pair(v,i2)));
				}
			}
		}

		vector<ll> cand(1,0);
		rep(i,k+1) rep(j,k+1) if(i!=j) {
			double x1=0,x2=0,x3=0;
			if(d[s1][i]<INF && d[s1][j]<INF) x1=crosspoint(i,d[s1][i],j,d[s1][j]).x;
			if(d[s1][i]<INF && d[s2][j]<INF) x2=crosspoint(i,d[s1][i],j,d[s2][j]).x;
			if(d[s2][i]<INF && d[s2][j]<INF) x3=crosspoint(i,d[s2][i],j,d[s2][j]).x;
			for(int k=-1;k<=1;k++){
				cand.push_back((ll)x1+k);
				cand.push_back((ll)x2+k);
				cand.push_back((ll)x3+k);
			}
		}
		sort(cand.begin(),cand.end());
		cand.erase(unique(cand.begin(),cand.end()),cand.end());

		ll ans=INF;
		rep(i,cand.size()) if(cand[i]>=0) {
			ll val1=eval(k,d[s1],cand[i]);
			ll val2=eval(k,d[s2],cand[i]);
			ans=min<ll>(ans,abs(val1-val2));
		}
		printf("%lld\n",ans);
	}

	return 0;
}