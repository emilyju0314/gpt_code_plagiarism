#include <bits/stdc++.h>
#define INF 1LL<<60
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int w,h;
ll K;
int n;
int x[100005],y[100005];
vector<int> vec[5005];
bool flag[10005];
ll cost[5005][3];
ll dp[5005];

ll calc(int y){
	for(int i=0;i<=(w+1)/2;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	sort(vec[y].begin(),vec[y].end());
	memset(flag,false,sizeof(flag));
	for(int i=0;i<vec[y].size();i++){
		flag[vec[y][i]]=true;
	}
	for(int i=0;i<(w+1)/2;i++){
		dp[i+1]=min(dp[i+1],dp[i]+(flag[i*2]?2:1));
		dp[i+2]=min(dp[i+2],dp[i]+(flag[i*2+1]?4:2));
	}
	return dp[(w+1)/2];
}

int main(void){
	scanf("%d%d%lld",&w,&h,&K);
	if((w+1)/2LL>K){
		printf("-1\n");
		return 0;
	}
	K-=(w+1)/2LL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]%2==1)continue;
		y[i]-=2;
		y[i]/=2;
		x[i]--;
		vec[y[i]].push_back(x[i]);
	}
	ll ans=0;
	ll pips=0;
	for(int i=0;i<h/2;i++){
		ans+=calc(i);
		pips+=(w+1)/2LL;
	}
	ll dcp=ans-pips;
	ans-=min(dcp,K)*2LL;
	K-=dcp;
	ans-=max(0LL,K);
	printf("%lld\n",max(ans,0LL));
	return 0;
}
