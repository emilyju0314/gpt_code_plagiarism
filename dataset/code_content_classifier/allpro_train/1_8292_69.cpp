#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct point
{
	ll x;
	ll y;
}p[N];
bool cmp(point a,point b)
{
	return atan2(a.x,a.y)<atan2(b.x,b.y);
}
int main()
{
	int n;	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	int nx[N];
	for(int i=1;i<=n;i++)
		nx[i]=i+1; nx[n]=1;
	sort(p+1,p+1+n,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll x=p[i].x;
		ll y=p[i].y;
		ans=max(ans,x*x+y*y);
		for(int j=nx[i];j!=i;j=nx[j])
		{
			x=x+p[j].x;
			y=y+p[j].y;
			ans=max(ans,x*x+y*y);
		} 
	}
	printf("%.10lf\n",sqrt(ans));
	return 0;
} 