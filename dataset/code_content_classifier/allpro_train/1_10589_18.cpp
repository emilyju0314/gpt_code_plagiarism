#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define LL long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int MOD=998244353;
int n,c[30];
LL dp[2][410][410][2][2][2][2];
inline int min(const int&x,const int&y){return x<y?x:y;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d",&n);
	for(register int i=0;i<26;i++)scanf("%d",c+i);
	int cur=0,nxt=1;
	for(register int a=0;a<2;a++)for(register int b=0;b<2;b++)
		for(register int c=0;c<2;c++)for(register int d=0;d<2;d++)
			dp[cur][n+1][n+1][a][b][c][d]=1;
	for(register int t=n-1;t>=0;t--){
		for(register int i=0;i<n+2;i++)for(register int j=0;j<n+2;j++)
			for(register int a=0;a<2;a++)for(register int b=0;b<2;b++)
				for(register int c=0;c<2;c++)for(register int d=0;d<2;d++){
					LL&res=dp[nxt][i][j][a][b][c][d];
					res=(24-(!a&&!c&&t>=2))*dp[cur][i][j][b][0][d][0];
					if(!a)res+=dp[cur][min(i+1,n+1)][j][b][1][d][0];
					if(!c)res+=dp[cur][i][min(j+1,n+1)][b][0][d][1];
					res%=MOD;
				}
		swap(cur,nxt);
	}
	LL ans=dp[cur][n+1][n+1][0][0][0][0];
	for(int i=0;i<26;i++)ans-=dp[cur][n-c[i]][n+1][0][0][0][0];
	for(int i=0;i<26;i++)for(int j=0;j<i;j++)
		ans+=dp[cur][n-c[i]][n-c[j]][0][0][0][0];
	printf("%lld\n",(ans%MOD+MOD)%MOD);
	return 0;
}
//stane stane stane