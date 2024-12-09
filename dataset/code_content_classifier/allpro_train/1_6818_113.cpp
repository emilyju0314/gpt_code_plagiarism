#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=310;
const int inf=2147483647;
const int mod=1000000007;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void upd(int&x,int y){x+=y;if(x>=mod)x-=mod;}
int n,a[Maxn<<1],c[Maxn<<1],f[Maxn<<1][Maxn][Maxn];//0 1
int main()
{
	n=read();
	for(int i=1;i<=(n<<1);i++)
	{
		a[i]=read();
		if(a[i]!=-1)c[a[i]]=1;
	}
	int cnt=0,m=n<<1;
	for(int i=1;i<=(n<<1);i+=2)
	{
		if(a[i]==-1||a[i+1]==-1)
		{
			if(a[i]==-1&&a[i+1]==-1)cnt++;
		}
		else c[a[i]]=c[a[i+1]]=-1,m-=2;
	}
	int t=0;
	for(int i=1;i<=(n<<1);i++)
	if(c[i]!=-1)c[++t]=c[i];
	f[m+1][0][0]=1;
	int ans;
	for(int i=m;i;i--)
	{
		if(c[i]==-1)continue;
		for(int j=0;j<=min(m-i+1,n);j++)
		for(int k=0;k<=min(m-i+1,n);k++)
		{
			if(c[i]==0)
			{
				upd(f[i][j][k],(LL)f[i+1][j][k+1]*(k+1)%mod);
				upd(f[i][j][k],f[i+1][j+1][k]);
				if(j)upd(f[i][j][k],f[i+1][j-1][k]);
			}
			else
			{
				upd(f[i][j][k],f[i+1][j+1][k]);
				if(k)upd(f[i][j][k],f[i+1][j][k-1]);
			}
//			if(f[i][j][k])printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
		}
	}
	ans=f[1][0][0];
	for(int i=2;i<=cnt;i++)ans=(LL)ans*i%mod;
	printf("%d",ans);
}