#include<bits/stdc++.h>
#define X first
#define Y second
#define F 1145141919
using namespace std;
vector<pair<int,int> > v[160];
int dp[80][160][12],n,m,k;
int Jump(int a,int b,int c,int d){
	if(v[a][b].X==-1||v[c][d].X==-1)return 0;
	int ret=abs(v[a][b].X-v[c][d].X);
	ret*=v[a][b].Y+v[c][d].Y;
	return ret;
}
int main(){
	pair<int,int> p;
	p.X=-1,p.Y=-1;
	v[0].push_back(p);
	while(cin>>n>>m&&n){
	for(int i=1;i<=n;i++){
		cin>>k;v[i].clear();
		while(k--){
			cin>>p.X>>p.Y;
			v[i].push_back(p);
		}
	}
	v[n+1].clear();p.X=-1,p.Y=-1;v[n+1].push_back(p);
	for(int i=0;i<80;i++)for(int j=0;j<160;j++)for(int k=0;k<12;k++)dp[i][j][k]=F;
	for(int i=0;i<=m;i++)dp[i][0][0]=0;
	for(int i=0;i<=m;i++){
		for(int f=0;f<=n;f++){
			for(int g=0;g<v[f].size();g++){
				for(int k=0;k<v[f+1].size();k++)dp[i][f+1][k]=min(dp[i][f+1][k],dp[i][f][g]+Jump(f,g,f+1,k));
				if(f!=n&&i!=m)for(int k=0;k<v[f+2].size();k++)dp[i+1][f+2][k]=min(dp[i+1][f+2][k],dp[i][f][g]+Jump(f,g,f+2,k));
			}
		}
	}
	int ans=F;
	for(int i=0;i<=m;i++)ans=min(ans,dp[i][n+1][0]);
	cout<<ans<<endl;
	}
	return 0;
}