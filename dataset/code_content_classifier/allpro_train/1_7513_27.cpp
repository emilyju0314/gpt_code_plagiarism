#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> vec[100005];
bool vis[100005];
int sg[100005];
void dfs(int x)
{sg[x]=0;vis[x]=1;
for (int i=0;i<vec[x].size();i++)
{if (!vis[vec[x][i]])
{dfs(vec[x][i]);sg[x]^=(sg[vec[x][i]]+1);}
}
}
int main (){
	int i,a,b;
	scanf ("%d",&n);
	for (i=1;i<n;i++)
	{scanf ("%d%d",&a,&b);
	vec[a].push_back(b);
	vec[b].push_back(a);
	}
	dfs(1);
	if (sg[1]==0)
	{puts("Bob");}
	else {puts("Alice");}
	return 0;
}