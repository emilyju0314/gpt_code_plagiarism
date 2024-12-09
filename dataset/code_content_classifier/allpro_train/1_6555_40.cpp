#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,v[100005];
vector<int> g[100005];
void dfs(int x){
	if(v[x])return ;
	v[x]=1;
	for(int y:g[x])dfs(y);
}
int main() {
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++)if(!v[i])dfs(i),ans++;
	cout<<ans-1;
	return 0;
}