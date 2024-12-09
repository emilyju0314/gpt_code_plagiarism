#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int ft[50],sz[50];
int rep[50];
int mul[50],inv[50],sf[50];
int f[41][41][1441][41];
int g[41][41][41][41];
int tmp[50],psm[1500];
int op[1500][41];
int fnd(int x)
{
	return x==ft[x]?x:ft[x]=fnd(ft[x]);
}
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d mul:%d inv:%d\n",i,mul[i],inv[i]);
}
int cb(int a,int b)
{
	return a<0||b<0||b>a?0:(ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
int cal(int *s)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=s[i]*sf[i+1];
	return ans;
}
void get(int x,int *s)
{
	for(int i=1;i<=n;i++)
		s[i]=x/sf[i+1],x%=sf[i+1];
}
int cs(int a)
{
	// if(a==0)
	// 	return mul[n-1];
	int ans=0;
	for(int i=0;i<=a;i++)
		(ans+=(ll)cb(a,i)*mul[i]%mod*mul[n-i-1]%mod)%=mod;
	return ans;
}
int main()
{
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
		ft[i]=i;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		ft[fnd(i)]=fnd(a);
	}
	for(int i=1;i<=n;i++)
		sz[fnd(i)]++;
	for(int i=1;i<=n;i++)
		if(sz[i])
			rep[sz[i]]++;
	sf[n+1]=1;
	for(int i=n;i>=1;i--)
		sf[i]=sf[i+1]*(rep[i]+1);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d rep:%d sf:%d\n",i,rep[i],sf[i]);
	// printf("1 1:%d\n",cs(1,1));
	int mx=sf[1]-1;
	// printf("mx:%d\n",mx);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int t=1;t<=n;t++)
				for(int r=1;r<=n;r++)
				{
					int ma=qpow(cs(i),t),mb=i==0?0:qpow(cs(i-j),t);
					g[i][j][t][r]=(ll)qpow((ma-mb+mod)%mod,r)*inv[r]%mod;
				}
	for(int s=0;s<=mx;s++)
	{
		// psm[s]=n;
		get(s,op[s]);
		for(int i=1;i<=n;i++)
			psm[s]+=op[s][i]*i;
	}
	f[0][0][mx][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			for(int t=1;t<=n;t++)
			{
				for(int s=0;s<=mx;s++)
				{
					if(psm[s]+i>n)
						continue;
					int *tmp=op[s];
					// get(s,tmp);
					// for(int k=n-i;k>=0;k--)
					// 	if(psm[s]+i+k==n)
					int k=n-psm[s]-i;
							for(int r=1;r<=tmp[t]&&i+k+r*t<=n;r++)
								f[i][j][s-r*sf[t+1]][k+r*t]=(f[i][j][s-r*sf[t+1]][k+r*t]+(ll)f[i][j][s][k]*g[i][j][t][r])%mod;
				}
			}
			for(int s=0;s<=mx;s++)
				for(int k=1;k<=n-i;k++)
				{
					// printf("i:%d j:%d s:%d k:%d f:%d\n",i,j,s,k,f[i][j][s][k]);
					// if(k)
						(f[i+k][k][s][0]+=f[i][j][s][k])%=mod;
				}
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		(ans+=f[n][i][0][0])%=mod;
	for(int i=1;i<=n;i++)
		ans=(ll)ans*mul[rep[i]]%mod;
	printf("%d",ans);
	return 0;
}