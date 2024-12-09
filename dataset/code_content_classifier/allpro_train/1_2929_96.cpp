#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ll;

const int MAX=1<<23;
const int MAXN=100100;

int data[MAX],datb[MAX];

void add(int a,int b,int x,int k,int l,int r)
{
	if(a<=l&&r<=b)data[k]+=x;
	else if(l<b&&a<r)
	{
		datb[k]+=(min(b,r)-max(a,l))*x;
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
	}
	return;
}

ll sum(int a,int b,int k,int l,int r)
{
	if(b<=l||r<=a)return 0;
	else if(a<=l&&r<=b)return data[k]*(r-l)+datb[k];
	else
	{
		ll res=(min(b,r)-max(a,l))*data[k];
		res+=sum(a,b,k*2+1,l,(l+r)/2);
		res+=sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}

int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	int p[MAXN];
	for(int i=0;i<m;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<m;i++)
	{
		add(min(p[i-1],p[i]),max(p[i-1],p[i]),1,0,0,n);
	}
	int a[MAXN],b[MAXN],c[MAXN];
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		ll s=sum(i,i+1,0,0,n);
		if(a[i]*s<b[i]*s+c[i])ans+=a[i]*s;
		else ans+=b[i]*s+c[i];
	}
	
	cout<<ans<<endl;
	return 0;
}