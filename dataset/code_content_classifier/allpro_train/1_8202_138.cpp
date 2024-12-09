#include<bits/stdc++.h>
using namespace std;
const int maxn=3010,mod=998244353;
inline void Add(int &a,int b){a=a+b>=mod?a+b-mod:a+b;}
inline int ksm(int a,int b)
{
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;
	return res;
}
int A,B,C,D,f[maxn][maxn];
int main()
{
	cin>>A>>B>>C>>D;
	f[A][B]=1;
	for(int i=A;i<=C;i++) for(int j=B;j<=D;j++)
	{
		Add(f[i+1][j],1ll*f[i][j]*j%mod);
		Add(f[i][j+1],1ll*f[i][j]*i%mod);
		Add(f[i+1][j+1],mod-1ll*f[i][j]*i%mod*j%mod);
	}
	cout<<f[C][D]<<endl;
}