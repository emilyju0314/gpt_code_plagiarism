#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct data{
	int bit,v;
	double cost;
	data(){}
	data(int bb,int vv,double cc){
		bit=bb;
		v=vv;
		cost=cc;
	}
	bool operator<(const data &d)const{
		return d.cost<cost;
	}
};

int n,m;
P za[201][2];
P factory[15];
double dist[1<<15][15];
double dp[15][15];
double stf[201][2][15];

struct graph_scc{
	int V;
	vector<int> G[501];
	vector<int> rG[501];
	vector<int> vs;
	bool used[501];
	int cmp[501];
	void init(int n){
		V=n;
		for(int i=0;i<V;i++){
			G[i].clear();
			rG[i].clear();
		}
		vs.clear();
		memset(cmp,0,sizeof(cmp));
	}
	void add_edge(int from,int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	void dfs(int v){
		used[v]=true;
		for(int i=0;i<G[v].size();i++){
			if(!used[G[v][i]])dfs(G[v][i]);
		}
		vs.push_back(v);
	}
	void rdfs(int v,int k){
		used[v]=true;
		cmp[v]=k;
		for(int i=0;i<rG[v].size();i++){
			if(!used[rG[v][i]])rdfs(rG[v][i],k);
		}
	}

	int scc(){
		memset(used,0,sizeof(used));
		vs.clear();
		for(int v=0;v<V;v++){
			if(!used[v])dfs(v);
		}
		memset(used,0,sizeof(used));
		int k=0;
		for(int i=vs.size()-1;i>=0;i--){
			if(!used[vs[i]]){
				rdfs(vs[i],k++);
			}
		}
		return k;
	}
};

graph_scc sc;

bool C(double v){
	sc.init(n*2);
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=i+1;k<n;k++){
				for(int l=0;l<2;l++){
					bool flag=false;
					for(int a=0;a<m;a++){
						for(int b=0;b<m;b++){
							double diss=stf[i][j][a];
							diss+=stf[k][l][b];
							diss+=dp[a][b];
							if(diss<=v)flag=true;
						}
					}
					if(!flag){
						sc.add_edge(i+j*n,k+(1-l)*n);
						sc.add_edge(k+l*n,i+(1-j)*n);
					}
				}
			}
		}
	}
	int k=sc.scc();
	for(int i=0;i<n;i++){
		if(sc.cmp[i]==sc.cmp[i+n])return false;
	}
	return true;
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&za[i][0].first,&za[i][0].second,&za[i][1].first,&za[i][1].second);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&factory[i].first,&factory[i].second);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<(1<<m);j++){
			for(int k=0;k<15;k++){
				dist[j][k]=1e9;
			}
		}
		dist[(1<<i)][i]=0.0;
		priority_queue<data> que;
		que.push(data(1<<i,i,0.0));
		while(que.size()){
			data d=que.top();
			que.pop();
			if(dist[d.bit][d.v]<d.cost)continue;
			for(int j=0;j<m;j++){
				int valx=(factory[j].first-factory[d.v].first);
				int valy=(factory[j].second-factory[d.v].second);
				double ncost=sqrt(valx*valx+valy*valy)+d.cost;
				if(dist[d.bit|(1<<j)][j]>ncost){
					dist[d.bit|(1<<j)][j]=ncost;
					que.push(data(d.bit|(1<<j),j,ncost));
				}
			}
		}
		for(int j=0;j<m;j++){
			dp[i][j]=dist[(1<<m)-1][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<m;k++){
				int valx=(za[i][j].first-factory[k].first);
				int valy=(za[i][j].second-factory[k].second);
				stf[i][j][k]=sqrt(valx*valx+valy*valy);
			}
		}
	}
	double l=0.0,r=114514.0;
	for(int i=0;i<50;i++){
		double mid=(l+r)/2.0;
		if(C(mid))r=mid;
		else l=mid;
	}
	printf("%.9f\n",r);
	return 0;
}