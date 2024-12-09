#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[110000];
vector<int>g[110000];
bool dame=false;
long long dfs(int a,int b){
	long long rem=c[a];
	if(g[a].size()>1)rem*=2;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		long long v=dfs(g[a][i],a);
		if(v>c[a])dame=true;
		rem-=v;
	}
	if(rem>c[a])dame=true;
	if(rem<0)dame=true;
	if(b==-1&&rem)dame=true;
	return rem;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	if(a==2){
		if(c[0]==c[1])printf("YES\n");else printf("NO\n");return 0;
	}
	int at=-1;
	for(int i=0;i<a;i++){
		if(g[i].size()>1){
			at=i;break;
		}
	}
	if(at==-1)return 1;
	dfs(at,-1);
	if(dame)printf("NO\n");else printf("YES\n");
}
