#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll ppow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int a[500];
ll dp[500][100000],dp2[500][100000];

int main(){
	int n;cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
	}
	dp[0][0]=1;
	dp2[0][0]=1;
	ll all=ppow(3,n);
	int cnt=0;
	rep(i,n){
		rep(j,cnt+1){
			if(dp[i][j]==0)continue;
			(dp[i+1][j]+=dp[i][j]*2)%=MOD;
			(dp[i+1][j+a[i]]+=dp[i][j])%=MOD;
			(dp2[i+1][j]+=dp2[i][j])%=MOD;
			(dp2[i+1][j+a[i]]+=dp2[i][j])%=MOD;
		}
		cnt+=a[i];
	}
	rep(i,cnt+1){
		if(cnt-i<i){
			if(dp[n][i]==0)continue;
			all=(all+MOD-dp[n][i]*3%MOD)%MOD;
		}
		else if(cnt-i==i){
			if(dp[n][i]==0)continue;
			all=(all+MOD-(dp[n][i])%MOD*3%MOD)%MOD;
			all=(all+dp2[n][i]*3%MOD)%MOD;
		}
	}
	cout<<all<<endl;
}