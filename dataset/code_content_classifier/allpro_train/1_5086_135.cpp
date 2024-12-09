#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
vector<int> adj[N];
long long dp[N][3];
void dfs(int x,int p){
	for(int i=0;i<adj[x].size();i++){
		if(adj[x][i]!=p){
			dfs(adj[x][i],x);
			dp[x][0]*=dp[adj[x][i]][1];
			dp[x][0]%=mod;
			dp[x][1]*=(dp[adj[x][i]][0]+dp[adj[x][i]][1]);
			dp[x][1]%=mod;
		}
	}
}
int main(){
	int n,i,j,k;
	cin>>n;
	for(i=1;i<n;i++){
		dp[i][1]=1;
		dp[i][0]=1;
		cin>>j>>k;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	dp[n][0]=1;
	dp[n][1]=1;
	dfs(1,1);
	cout<<(dp[1][0]+dp[1][1])%mod;
}