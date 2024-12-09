#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6,p=1e9+7;
int x,y;
long long fac[maxn],inv[maxn];

long long poww(long long x,long long y)
{
	long long ans=1,tmp=x;
	while(y) {
		if(y&1) ans=ans*tmp%p;
		tmp=tmp*tmp%p;
		y>>=1;
	}
	return ans;
}

long long c(int x,int y)
{
	return (((fac[x]*inv[y])%p)*inv[x-y])%p;
}

int main()
{
	scanf("%d %d",&x,&y);
	if((
	x+y)%3!=0) {
		printf("0");
		return 0;
	}
	int n=(2*x-y)/3,m=(2*y-x)/3;
	if(n<0||m<0) {
		printf("0");
		return 0;
	}
	fac[0]=1;inv[0]=1;
	for(int i=1;i<maxn;++i) fac[i]=fac[i-1]*i%p;
	inv[maxn-1]=poww(fac[maxn-1],p-2);
	for(int i=maxn-2;i>=1;--i) inv[i]=inv[i+1]*(i+1)%p; 
	printf("%lld",c(n+m,n)); 
}