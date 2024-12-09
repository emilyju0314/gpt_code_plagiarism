/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-12 10:42:26
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=200010,mod=1000000007,i2=(mod+1)/2;
i64 n,s[N],v[N],w[N],zr[N],lst[N],a[N],b1[N],b2[N],ans,Ans;
i64 &Add(i64 &a,i64 b){ return a=(a+b)%mod; }
void add(i64 *b,int p,i64 v)
{
	while(p){ Add(b[p],v); p-=p&(-p); }
}
i64 query(i64 *b,int p)
{
	i64 ans=0;
	while(p<=n){ Add(ans,b[p]); p+=p&(-p); }
	return ans;
}
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1; a%=p;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
i64 Query(i64 *b,int l,int r){ return (query(b,l)-query(b,r+1)+mod)%mod; }
int main()
{
	n=read();
	fr(i,1,n) s[a[i]=read()]++;
	fd(i,n,1) s[i]+=s[i+1];
	Ans=1;
	fr(i,1,n)
	{
		v[i]=s[i]-(n-i); Ans=Ans*v[i]%mod;
		if(!v[i]){ printf("0\n"); return 0; }
		if(v[i]-1){ zr[i]=zr[i-1]; w[i]=w[i-1]*(v[i]-1)%mod*inv(v[i])%mod; }
		else{ zr[i]=zr[i-1]+1; w[i]=1; }
		lst[zr[i]]=i;
	}
	fd(i,n,1)
	{
		Add(ans,Ans*(inv(w[a[i]])*Query(b1,a[i]+1,lst[zr[a[i]]])%mod*i2%mod));
		add(b1,a[i],w[a[i]]);
	}
//	printf("%d\n",int(Ans));
//	fr(i,1,n) printf("%d%c",int(zr[i]),i==n?'\n':' ');
	fr(i,1,n) b1[i]=0;
	fr(i,1,n)
	{
		Add(ans,Ans*(Query(b2,a[i],n)-Query(b1,a[i],lst[zr[a[i]]])*inv(w[a[i]])%mod*i2%mod+mod)%mod);
		add(b1,a[i],w[a[i]]); add(b2,a[i],1);
	}
	printf("%d\n",int(ans));
	return 0;
}