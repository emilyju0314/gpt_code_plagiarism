#include<bits/stdc++.h>
#define N 100100
using namespace std;
int dep[N];
vector<int> g[N];
bool cmp(int a,int b){
	return dep[a]>dep[b];
}
int DFS(int u){
	if(g[u].empty()) return dep[u]=0;
	for(int i=0;i<g[u].size();i++) DFS(g[u][i]);
	sort(g[u].begin(),g[u].end(),cmp);
	for(int i=0;i<g[u].size();i++){
		dep[u]=max(dep[u],dep[g[u][i]]+i+1);
	}
	return dep[u];
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) scanf("%d",&x),g[x].push_back(i);
	printf("%d\n",DFS(1));
	return 0;
}