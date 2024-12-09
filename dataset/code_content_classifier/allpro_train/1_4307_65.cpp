#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll p[10000],c[10000];
ll ans=-1000000000000000000LL;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		int next=p[i];
	    int l=1;
	    ll s=c[next];
		ans=max(ans,s);
	    while(l<k&&next!=i)
		{
	    	next=p[next];
	    	s+=c[next];
	    	ans=max(ans,s);
	    	l++;
	    }
	    if(s>=0LL&&l<k)
		{
	    	s*=(ll)((k-l)/l);
	    	int t=k%l+l;
	    	while(t>0)
			{
		        next=p[next];
		        s+=c[next];
		        if(s>ans) ans=s;        
		        t--;
			}
		}
	}
	cout<<ans;
	return 0;
}