#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

#define so(a) ((int)((a).size()))

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

const char lf = '\n';

namespace ae86
{
	const int bufl = 1 << 15;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline int ty()
	{
		int a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 100007 , D = 3 , __ = _ * D , LIM = 512 , mo = 998244353;
const lint linf = 1000000000000000000;

template<typename T1,typename T2> inline T1 ad(T1 &a,T2 b){return a=a+b>=mo?a+b-mo:a+b;}
template<typename T1,typename T2> inline T1 dl(T1 &a,T2 b){return a=a>=b?a-b:a-b+mo;}
template<typename T1,typename T2> inline T1 add(T1 a,T2 b){return a+b>=mo?a+b-mo:a+b;}
template<typename T1,typename T2> inline T1 del(T1 a,T2 b){return a>=b?a-b:a-b+mo;}

lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a){return powa(a,mo-2);}

vector<int> e[_];
lint bas[__];
int n,sg[_];

void makef(lint f[])
{
	int m=ty();
	for(int i=1;i<=n;i++)sg[i]=0,e[i].clear();
	for(int i=1,a,b;i<=m;i++)a=ty(),b=ty(),e[min(a,b)].emplace_back(max(a,b));
	for(int i=n;i>=1;i--)
	{
		unordered_set<int> hav;
		for(auto b:e[i])hav.emplace(sg[b]);
		sg[i]=0;
		while(hav.count(sg[i]))sg[i]++;
	}
	for(int i=0;i<LIM;i++)f[i]=0;
	for(int i=1;i<=n;i++)ad(f[sg[i]],bas[i]);	
}

lint f[D][LIM];

int main()
{
	ios::sync_with_stdio(0),cout.tie(nullptr);

	n=ty();
	bas[0]=1;
	for(int i=1;i<__;i++)bas[i]=bas[i-1]*(linf%mo)%mo;
	for(int i=0;i<D;i++)makef(f[i]);

	lint ans=0;
	for(int i=0;i<LIM;i++)
		for(int j=0;j<LIM;j++)
			ad(ans,f[0][i]*f[1][j]%mo*f[2][i^j]%mo);
	cout<<ans<<lf;
	
	return 0;
}
