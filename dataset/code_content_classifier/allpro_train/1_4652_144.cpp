#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1e9;
struct node
{
	int a[2];
}a[21];
void dfs(int x,int y)
{
	if(y>=ans)
	return;
	if(x==n+1)
	{
		ans=y;
		return;
	}
	for(int i=x;i<=n;i++)
	if(a[i].a[(i-x)%2]>=a[x-1].a[0])
	{
		for(int j=i;j>x;j--)
		{
			swap(a[j].a[0],a[j-1].a[1]);
			swap(a[j].a[1],a[j-1].a[0]);
		}
		dfs(x+1,y+i-x);
		for(int j=x;j<i;j++)
		{
			swap(a[j].a[0],a[j+1].a[1]);
			swap(a[j].a[1],a[j+1].a[0]);
		}
	}
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].a[0]);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].a[1]);
	dfs(1,0);
	if(ans!=1e9)
	printf("%d",ans);
	else
	printf("-1");
	return 0;
}