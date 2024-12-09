#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=2e5+5;
ll a[MN],N,t1,t2,t3,ans;
ll cal(ll x,ll y,ll z)
{
	ll _1=a[x],_2=a[y]-a[x],_3=a[z]-a[y],_4=a[N]-a[z];
	return abs(max(max(_1,_2),max(_3,_4))-min(min(_1,_2),min(_3,_4)));
}
int main()
{
	N=read();
	reg int i;
	for(i=1;i<=N;++i) a[i]=read()+a[i-1];
	t1=1;t2=2;t3=3;ans=cal(1,2,3);
	for(;t2<=N-2;++t2)
	{
		while(t1+1<t2&&abs(a[t2]-2*a[t1+1])<abs(a[t2]-2*a[t1]))++t1;
		while(t3+1<N&&abs(a[N]-2*a[t3+1]+a[t2])<abs(a[N]-2*a[t3]+a[t2]))++t3;
		ans=min(ans,cal(t1,t2,t3));
	}
	return 0*printf("%lld\n",ans);
}