#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int maxn = 4e5+5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vector<int> G[maxn];
int d[maxn];
vector<int> maxd[maxn];
queue<int> QQQ;

int level[maxn],link[maxn];
int dist[maxn][20];
int dfs(int rt,int fa,int& gra,int n)
{
	int sum=1;
	for(int u:G[rt])
		if(u!=fa && level[u]==-1)
			sum+=dfs(u,rt,gra,n);
	if(gra==-1 && (fa==-1 || sum*2>n))
		gra = rt;
	return sum;
}
void build(int rt,int n,int dep,int fa){
	int gra=-1;
	dfs(rt,-1,gra,n);
	level[gra] = dep;
	link[gra] = fa;
	for(int u:G[gra])
		if(level[u]==-1)
			build(u,n/2,dep+1,gra);
}

void calc(int rt,int fa,int dep,const int row){
	if((int)maxd[row].size()<=dep) maxd[row].push_back(d[rt]);
	else maxd[row][dep]=max(maxd[row][dep],d[rt]);
	dist[rt][level[rt]-level[row]] = dep;
	for(int u:G[rt]){
		if(u!=fa && level[u]>level[row])
			calc(u,rt,dep+1,row);
	}
}

bool check(int v,int x){
	for(int i=0,u=v;u!=-1;u=link[u],i++){
		if(dist[v][i]<=x && maxd[u][min((int)maxd[u].size()-1,x-dist[v][i])]>x)
			return 1;
	}
	return 0;
}


int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(d,-1,sizeof d);
	int k;scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int u;
		scanf("%d",&u);
		d[u]=0;
		QQQ.push(u);
	}
	while(!QQQ.empty()){
		int x=QQQ.front();QQQ.pop();
		for(int y:G[x])
			if(d[y]==-1){
				d[y]=d[x]+1;
				QQQ.push(y);
			}
	}
	memset(level,-1,sizeof level);
	build(1,n,1,-1);
	for(int i=1;i<=n;i++){
		// printf("%d link %d\n", i,link[i]);
		calc(i,-1,0,i);
	}
	for(int i=1;i<=n;i++){
		int sz = maxd[i].size();
		for(int j=1;j<sz;j++)
			maxd[i][j] = max(maxd[i][j-1],maxd[i][j]);
	}
	for(int i=1;i<=n;i++){
		int l=0,r=n;
		// int ans;
		while(l<r){
	// printf("build %d %d\n",l,r);
			int mid = (l+r)>>1;
			if(check(i,mid)){
				// ans = mid+1;
				l=mid+1;
			}
			else
				r=mid;
		}
		printf("%d ",l);
	}
}
