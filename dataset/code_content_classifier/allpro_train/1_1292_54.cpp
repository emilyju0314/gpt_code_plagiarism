#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=2e3+10;
int n,k,ans=1e9,res;
vector<int> g[maxn<<1];

void dfs(int pos,int fa,int dep){
	if(dep>k&&pos<=n)
		++res;
	for(int i=0;i<g[pos].size();++i)
		if(g[pos][i]!=fa)
			dfs(g[pos][i],pos,dep+1);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(n+i);
		g[n+i].push_back(u);
		g[v].push_back(n+i);
		g[n+i].push_back(v);
	}
	for(int i=1;i<2*n;++i){
		res=0;
		dfs(i,0,0);
		if(res<ans)
			ans=res;
	}
	printf("%d\n",ans);
	return 0;
}