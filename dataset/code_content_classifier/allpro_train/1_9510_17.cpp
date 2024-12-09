#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
ll p,n;
ll C[3333][3333],S2[3333][3333];
ll F[3333];
ll qpow(ll x,ll y,ll m){ll r=1;for(;y;y>>=1,(x*=x)%=m)if(y&1)(r*=x)%=m;return r;}

int main()
{
	register int i,ii;
	scanf("%lld%lld",&n,&p),S2[0][0]=1;
	for(i=0;i<=3005;i++)C[i][0]=C[i][i]=1;
	for(i=1;i<=3005;i++)
		for(ii=1;ii<=3005;ii++)
			C[i][ii]=(C[i-1][ii-1]+C[i-1][ii])%p,S2[i][ii]=(S2[i-1][ii-1]+ii*S2[i-1][ii])%p;
	for(i=0;i<=n;i++)
	{
		ll pw2=1,qw2=qpow(2,n-i,p);
		for(ii=0;ii<=i;ii++,(pw2*=qw2)%=p)(F[i]+=S2[i+1][ii+1]*pw2)%=p;
		F[i]=F[i]*C[n][i]%p*qpow(2,qpow(2,n-i,p-1),p)%p;
	}ll ans=0;
	for(i=0;i<=n;i++)ans+=p+((i&1)?-1:1)*F[i];
	printf("%lld\n",ans%p);
}
/*
Just go for it.
*/