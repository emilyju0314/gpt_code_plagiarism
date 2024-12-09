#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=2e5+100;
long long  t,m,n,d,idx,idy,s[N],ss[N],a[N],b[N],c[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long minx=1e9;
		idx=0,idy=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			cin>>d;
			if(d==1)
				b[++idx]=a[i];
			else
				c[++idy]=a[i];
		}
			sort(b+1,b+idx+1,cmp);
			sort(c+1,c+idy+1,cmp);
		for(int i=1;i<=idx;i++)
	    {
	    	ss[i]=ss[i-1]+b[i];
		}
		for(int i=1;i<=idy;i++)
	    {
	    	s[i]=s[i-1]+c[i];
		}
		if(ss[idx]+s[idy]<m)
		{
			cout<<-1<<endl;
			continue;
		}
			for(int i=0;i<=idy;i++)//遍历+二分 
			{
				long long l=0,r=idx;
				while(l<=r)
				{
					long long mid=l+r>>1;
					if(s[i]+ss[mid]>=m)
					{
						minx=min(minx,2*i+mid);
						r=mid-1;
					}
					else
					{
						l=mid+1;
					}
				}
				
			}
			
			cout<<minx<<endl;
	} 
		return 0;
} 