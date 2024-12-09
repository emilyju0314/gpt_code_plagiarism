#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int f[1005][1005][2],aux[1005][2],a[1005],n,tot;
int fac[1005],inv[1005],p2[1005];
int add(int a,int b){a+=b; return a>=mod?a-mod:a;}
void Inc(int &a,int b){a=add(a,b);}
int ksm(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1) s=1ll*s*a%mod;
	return s;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
void Solve(int p,int l,int r,int lim)
{
	int mval=1e9,mpos;
	if(l==r) f[p][0][1]=f[p][1][0]=1,mval=a[l],mpos=l;
	else
	{
		for(int i=l;i<=r;i++) if(mval>a[i]) mval=a[i],mpos=i;
		if(mpos==l||mpos==r)
		{
			int id=++tot;
			Solve(id,l+(mpos==l),r-(mpos==r),mval);
			for(int ty=0;ty<2;ty++)
				for(int i=(!ty);i<=r-l+1;i++)
					f[p][i][ty]=f[id][i-!(ty)][ty];
		}
		else
		{
			int ls=++tot,rs=++tot;
			Solve(ls,l,mpos-1,mval),Solve(rs,mpos+1,r,mval);
			for(int i=0;i<=mpos-l;i++)
				for(int j=0;j<=r-mpos;j++)
					for(int ty=0;ty<2;ty++)
						Inc(f[p][i+j+!(ty)][ty],1ll*f[ls][i][ty]*f[rs][j][ty]%mod);
		}
	}
	int L=r-l+1;
	for(int t=mval-1;t>=lim;t--)
	{
		for(int i=0;i<=L;i++)
		{
			Inc(aux[i][0],f[p][i][0]);
			Inc(aux[i][1],f[p][i][0]);
			for(int j=0;j<=i;j++)
			{
				Inc(aux[j][1],1ll*f[p][i][1]*C(i,i-j)%mod*(p2[L-i]-(i==j))%mod);
				Inc(aux[j][0],1ll*f[p][i][0]*C(i,i-j)%mod*(p2[L-i]-(i==j))%mod);
			}
		}
		for(int i=0;i<=L;i++) f[p][i][0]=aux[i][0],f[p][i][1]=aux[i][1],aux[i][0]=aux[i][1]=0;
	}
}
void Pre()
{
	fac[0]=p2[0]=1;
	for(int i=1;i<=1000;i++) fac[i]=1ll*fac[i-1]*i%mod,p2[i]=add(p2[i-1],p2[i-1]);
	inv[1000]=ksm(fac[1000],mod-2);
	for(int i=999;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int main()
{
	Pre();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	Solve(++tot,1,n,0);
	printf("%d\n",f[1][0][1]);
	return 0;
}