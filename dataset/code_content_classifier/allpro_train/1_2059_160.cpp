#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,d[maxn],siz[maxn],f,dis;
map <ll,int> p;
vector <int> a1,a2;

inline bool cmp(ll a,ll b){return a>b;}

int main()
{
	n=read(); f=0;
	for(int i=1;i<=n;i++) d[i]=read(),p[d[i]]=i;
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		siz[p[d[i]]]++;
		ll dfa=d[i]-n+2*siz[p[d[i]]];
		if(dfa>d[i]) continue;
		siz[p[dfa]]+=siz[p[d[i]]]; dis+=siz[p[d[i]]];
		//cout<<d[i]<<" "<<p[d[i]]<<" "<<siz[p[d[i]]]<<" "<<dfa<<endl;
		if(p[dfa]==0) {f=1; break;}
		a1.push_back(p[d[i]]),a2.push_back(p[dfa]);
	}
	if(f==1||dis!=d[n]) {puts("-1"); return 0;}
	for(int i=0;i<a1.size();i++) printf("%d %d\n",a1[i],a2[i]);
	return 0;
}