#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
typedef long long ll;
vector<pair<int,int> > G[N];
int ans[N];
bool vis[N];
void dfs(int now){
	vis[now]=1;
	for(auto v:G[now]){
		if(!vis[v.first]){
			if(v.second&1){
				ans[v.first]=!ans[now];
			}
			else ans[v.first]=ans[now];
			dfs(v.first);	
		}
	}
}
int main(){
	int n;
	cin>>n;
	int u,v,w;
	for(int i=1;i<=n-1;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	ans[1]=0;
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
