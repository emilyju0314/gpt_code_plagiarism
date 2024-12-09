#include <bits/stdc++.h>
#define debug freopen("r.txt","r",stdin)
#define mp make_pair
#define ri register int
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<ll, ll> pii;
const int maxn = 1e6+10;
const int N = 1500+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int hash_num = 131;
const double eps=1e-6;
const double PI=acos(-1.0);
inline ll read(){ll s=0,w=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
return s*w;}
ll qpow(ll p,ll q){return (q&1?p:1)*(q?qpow(p*p%mod,q/2):1)%mod;}
int t,n,a[maxn],f[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		debug;
	#endif
	t=read();
	while (t--)
	{
		n=read();
		for (int i = 1; i <= n; ++i)
		{
			a[i] =read();
			f[i]=0;
		}
		f[n+1]=0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i]>0)
			{
				f[max(i-a[i]+1,1)]++;
				f[i+1]--;
				// for (int j = 0; j<=a[i]-1 ; ++j)
				// {
				// 	if (i-j==0) break;
				// 	if (f[i-j]==1) break;
				// 	else f[i-j]=1;
				// }
			}
		}
		for (int i = 1; i <= n; ++i) f[i]=f[i-1]+f[i];
		for (int i = 1; i <= n; ++i) 
			if (f[i]) cout << 1 << " ";
			else cout << 0 <<" ";
		cout <<endl;
	}
	return 0;
}