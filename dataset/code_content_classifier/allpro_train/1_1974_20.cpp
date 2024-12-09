#include<iostream>
#include<vector>
using namespace std;
vector<int>G[1<<17];
int used[1<<17];
long n,m;
bool dfs(int u,int col)
{
	used[u]=col;
	int next=-col;
	bool ans=true;
	for(int i=0;i<G[u].size();i++)
	{
		if(used[G[u][i]]){if(used[G[u][i]]!=next)ans=false;}
		else ans&=dfs(G[u][i],next);
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;cin>>a>>b;
		G[a].push_back(b);G[b].push_back(a);
	}
	if(dfs(1,1))
	{
		long cnt=0;
		for(int i=0;i++<n;)cnt+=used[i]==1;
		cout<<cnt*(n-cnt)-m<<endl;
	}
	else cout<<n*~-n/2-m<<endl;
}