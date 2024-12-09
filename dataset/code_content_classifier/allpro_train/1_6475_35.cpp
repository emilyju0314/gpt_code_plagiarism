#include<bits/stdc++.h>
using namespace std;
#define fi first
#define mp make_pair
#define se second
const int N=305,M=1e9+7;
vector<pair<int,int> > v[N];
int x,y,z,n,m,dp[N][N][N];
int check(int x,int y,int z){
	if (x&&y&&x==y)return 0;
	if (x&&z&&x==z)return 0;
	if (y&&z&&y==z)return 0;
	int t=max(x,max(y,z));
	for (int i=0;i<(int)v[t].size();i++){
		int cnt=0;
		cnt+=x>=v[t][i].fi;
		cnt+=y>=v[t][i].fi;
		cnt+=z>=v[t][i].fi;
		if (cnt!=v[t][i].se)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[y].push_back(mp(x,z));
	}
	dp[0][0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (check(i,j,k)){
					int t=max(i,max(j,k))+1;
					(dp[t][j][k]+=dp[i][j][k])%=M;
					(dp[i][t][k]+=dp[i][j][k])%=M;
					(dp[i][j][t]+=dp[i][j][k])%=M;
				}
	int ans=0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n;k++)
				if (check(i,j,k)&&max(i,max(j,k))==n)(ans+=dp[i][j][k])%=M;
	printf("%d\n",ans);
}
