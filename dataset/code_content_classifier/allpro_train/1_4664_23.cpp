#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>g[40];
int v[40];
int deg[40];
pair<int,int>pt[40];
int n;
int dfs(int a){
	if(a==n){
		return 0;
	}
	int ret=999999999;
	v[pt[a].second]=-1;
	bool ok=true;
	for(int i=0;i<=a;i++){
		int f=pt[i].second;
		if(~v[f])continue;
		bool OK=false;
		for(int j=0;j<g[f].size();j++)if(~v[g[f][j]]){OK=true;break;}
		if(!OK){ok=false;break;}
	}
	if(ok){
		ret=min(ret,dfs(a+1));
	}
	v[pt[a].second]=1;
	ret=min(ret,dfs(a+1)+1);
	v[pt[a].second]=0;
	return ret;
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		n=a;
		for(int i=0;i<a;i++)g[i].clear();
		for(int i=0;i<a;i++)v[i]=0;
		for(int i=0;i<b;i++){
			int p,q;scanf("%d%d",&p,&q);
			g[p].push_back(q);g[q].push_back(p);
			deg[p]++;deg[q]++;
		}
		int ret=0;
		for(int i=0;i<a;i++)pt[i]=make_pair(deg[i],i);
		ret=dfs(0);
		printf("%d\n",ret);
	}
}