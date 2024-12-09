#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define lowbit(x) (x&-x) 
using namespace std; 
const int MAXN = 500005; 
int a[MAXN],n,c[MAXN];
typedef long long ll;
inline void add(int &x,int a)
{
	x+=a;
	if(x>=MOD)x-=MOD;
}
inline void add(int x)
{
	for(;x<=n;x+=lowbit(x))add(c[x],1);
}
inline int sum(int x) {
	int ret=0;
	for(;x;x-=lowbit(x))add(ret,c[x]);
	return ret;
}
inline int ksm(int x,int k)
{
	int ret=1;
	while(k){
		if(k&1)ret=(ll)ret*x%MOD;
		x=(ll)x*x%MOD;
		k>>=1;
	}
	return ret;
}
int s[MAXN];
int ans=0,tot,fac[MAXN],t[MAXN],inv,inv1,ave;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i])s[a[i]]=1;
		else ++tot;
	}
	for(int i=1;i<=n;++i){
		if(!s[i])add(ave,i-1);
		s[i]=s[i-1]+s[i];
	}
	inv=ksm(tot,MOD-2);
	inv1=ksm(tot-1,MOD-2);
	int now=0,t=0;
	for(int i=1;i<=tot;++i){
		add(t,(ll)(i-1)*inv1%MOD);
	}
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=(ll)fac[i-1]*i%MOD;
	t=(ll)t*inv%MOD;
	int del=0;
	for(int i=1;i<n;++i){
		int o=sum(a[i]);
		if(!a[i])add(ans,(ll)(((ll)ave*inv%MOD-(ll)now*t%MOD+MOD)%MOD-del+MOD)%MOD*fac[tot]%MOD*fac[n-i]%MOD);
		else add(ans,(ll)(((a[i]-1+MOD)%MOD-o+MOD)%MOD-(ll)now*(a[i]-s[a[i]])%MOD*inv%MOD+MOD)%MOD*fac[tot]%MOD*fac[n-i]%MOD);
		if(a[i]) add(del,(ll)(tot-(a[i]-s[a[i]]))*inv%MOD),add(a[i]);
		else ++now;
	}
	add(ans,fac[tot]);
	cout<<ans<<endl;
	return 0;
}  
