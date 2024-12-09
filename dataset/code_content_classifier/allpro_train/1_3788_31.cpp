#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,N=1e5+50;
int a[N],b[N];
int main()
{
	int A,B,m,ans,maxa=inf,maxb=inf;
	cin>>A>>B>>m;
	for (int i=0;i<A;i++)
	{
		cin>>a[i];
		maxa=min(a[i],maxa);
	}
	for (int i=0;i<B;i++)
	{
		cin>>b[i];
		maxb=min(b[i],maxb);
	}
	ans=maxa+maxb;
	for (int i=0;i<m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		x--; y--;
		ans=min(ans,a[x]+b[y]-c);
	}
	cout<<ans;
	return 0;
}