#include<cstdio>
#include<queue>
using namespace std;
int n,i;
long long a[300010],f[300010],g[300010],s,ans;
priority_queue<long long>q;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=3*n;i++) scanf("%lld",&a[i]);
	for (i=1;i<=n;i++)
	{
		q.push(-a[i]);
		s-=a[i];
	}
	f[n]=s;
	for (i=n+1;i<=2*n;i++)//ending of the first half
	{
		long long x=q.top();
		q.pop();
		f[i]=f[i-1]-x-a[i];
		q.push(-a[i]);
	}
	while (!q.empty()) q.pop();
	s=0;
	for (i=2*n+1;i<=3*n;i++)
	{
		q.push(a[i]);
		s+=a[i];
	}
	g[2*n+1]=s;
	for (i=2*n;i>=n+1;i--)
	{
	    q.push(a[i]);
		long long x=q.top();
		q.pop();
		g[i]=g[i+1]-x+a[i];	
	}
	ans=f[n]+g[n+1];
	for (i=n+1;i<=2*n;i++)
	{
		ans=min(ans,f[i]+g[i+1]);
	}
	printf("%lld\n",-ans); 
}