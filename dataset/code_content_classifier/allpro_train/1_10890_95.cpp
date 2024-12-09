using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 18
#define ll long long
#define mo 998244353
ll qpow(ll x,int y=mo-2){
	ll r=1;
	for (;y;y>>=1,x=x*x%mo)
		if (y&1)
			r=r*x%mo;
	return r;
}
int n;
int a[1<<N],p[1<<N],e[1<<N],f[1<<N];
void fwt(int F[]){
	for (int i=1;i<1<<n;i<<=1)
		for (int j=0;j<1<<n;j+=i<<1)
			for (int k=j;k<j+i;++k){
				int x=F[k],y=F[k+i];
				F[k]=(x+y)%mo;
				F[k+i]=(x-y+mo)%mo;
			}
}
int main(){
	scanf("%d",&n);
	ll sum=0;
	for (int i=0;i<1<<n;++i)
		scanf("%d",&a[i]),sum+=a[i];
	sum=qpow(sum);
	for (int i=0;i<1<<n;++i)
		p[i]=a[i]*sum%mo;
	
	for (int i=0;i<1<<n;++i)
		f[i]=-1+mo;
	(f[0]+=1<<n)%=mo;
	fwt(f);
	(p[0]=p[0]-1+mo)%=mo;
	fwt(p);
	
	sum=0;
	for (int i=1;i<1<<n;++i){
		e[i]=(ll)f[i]*qpow(p[i])%mo;
		sum+=e[i];
	}
	e[0]=(mo-sum%mo)%mo;
	fwt(e);
	ll inv=qpow(1<<n);
	for (int i=0;i<1<<n;++i)
		e[i]=e[i]*inv%mo;
	for (int i=0;i<1<<n;++i)
		printf("%d\n",e[i]);
	return 0;
}