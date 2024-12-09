#include <iostream>
using namespace std;
int n,m,a[20][20],c[20],X,now[20];
int ans=1e9;
inline void dfs(int x,int nw)
{
	if(x==n+1)
	{
		for(int i=1;i<=m;i++)
			if(now[i]<X) return ;
		ans=min(ans,nw);
		return ;
	}
	for(int i=1;i<=m;i++)
		now[i]+=a[x][i];
	dfs(x+1,nw+c[x]);
	for(int i=1;i<=m;i++)
		now[i]-=a[x][i];
	dfs(x+1,nw);
}
int main(int argc, char** argv) {
	cin >> n >> m >> X;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	}
	dfs(1,0);
	if(ans<=5e8)
		cout << ans;
	else puts("-1");
	return 0;
}