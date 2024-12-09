#include<bits/stdc++.h>
using namespace std;

bool dp[4001][16001];
int x,y,tx,ty,ax[4001],ay[4001];

void dfsx(int t,int n){
	if(dp[t][n+8000])return;
	if(t<tx){
		dfsx(t+1,n+ax[t]);
		dfsx(t+1,n-ax[t]);
	}
	dp[t][n+8000]=1;
}

void dfsy(int t,int n){
	if(dp[t][n+8000])return;
	if(t<ty){
		dfsy(t+1,n+ay[t]);
		dfsy(t+1,n-ay[t]);
	}
	dp[t][n+8000]=1;
}

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s>>x>>y;
	bool fx=1;
	for(int i=0;i<s.length();++i){
		if(s[i]=='F'){
			if(fx)++ax[tx];
			else ++ay[ty];
		}else{
			if(fx)fx=0,++tx;
			else fx=1,++ty;
		}
	}
	if(s[s.length()-1]=='F'){
		if(fx)++tx;
		else ++ty;
	}
	dfsx(1,ax[0]);
	bool xx=dp[tx][8000+x]==1?1:0;
	memset(dp,0,sizeof(dp));
	dfsy(0,0);
	bool yy=dp[ty][8000+y]==1?1:0;
	if(xx&&yy)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}