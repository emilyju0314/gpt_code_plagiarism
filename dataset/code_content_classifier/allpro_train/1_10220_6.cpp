#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000005;
int a[maxn],b[maxn],opt[maxn],limit[maxn],x[maxn],y[maxn],L,R,n,m;
int check(int mid)
{
//	cout<<mid<<" "<<a[mid]<<" ";
	int now=a[mid];
	for(int i=1;i<=m;i++)
	{
		if(opt[i]==1)
		{
			if(now>=limit[i])now=(now+x[i])*y[i];
		}
		else if(now<=limit[i])now=(now-x[i])/y[i];	
	}
	
//	cout<<now<<endl;
	return now;
}
signed main()
{
	cin>>n>>m>>L>>R;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>opt[i]>>limit[i]>>x[i]>>y[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans1=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)<=R)ans1=mid,l=mid+1;
		else r=mid-1; 
	} 
//	cout<<ans1<<endl;
	l=1,r=n;int ans2=n+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)>=L)ans2=mid,r=mid-1;
		else l=mid+1; 
	} //cout<<ans2<<endl;
	cout<<ans1-ans2+1<<endl;
	
}
/*
3 3 3 10
1 -2 3
1 2 2 3
2 20 1 3
2 1 20 5
首先那些不构成约束的边直接就是2^k/2，随便取，然后有一半的概率是不合法的
对于有约束的边就看下约束
每次枚举一个点，然后开始检查所有边 
 
 */
