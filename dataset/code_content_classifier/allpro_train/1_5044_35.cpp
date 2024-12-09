#include<bits/stdc++.h>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
using namespace std;	

const int mxn=2e5+5,mod=1e9+7;
int dp[mxn][20],a[mxn],nxt[mxn],n;
vector<int>prime_factors[mxn];

void sieve(){
	for(int i=2;i<mxn;i++){
		if(prime_factors[i].empty()){
			nxt[i]=mxn;
			for(int j=1;i*j<mxn;j++)
				prime_factors[i*j].push_back(i);
		}
	}
}

void lifting(){
	dp[n+1][0]=n+1;

	for(int i=n;i>=1;i--){
		dp[i][0]=dp[i+1][0];
		for(auto x:prime_factors[a[i]]){
			dp[i][0]=min(dp[i][0],nxt[x]);
			nxt[x]=i;	
		}
	}
	for(int i=1;i<=19;i++){
		for(int j=1;j<=n+1;j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	}
}


void solve(){
	int q,i,j;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sieve();
	lifting();
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=0;
		for(i=19;i>=0;i--){
			if(dp[l][i]<=r){
				ans+=1<<i;
				l=dp[l][i];
			}
		}
		cout<<ans+1<<'\n';
	}
}


int main(void){
	fast;
	solve();
}
