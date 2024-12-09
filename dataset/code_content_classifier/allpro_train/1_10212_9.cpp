#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
int p2[9],dp[500001];
int solve(vector<int> a){
	int n=a.size(),sum=0;
	rep(i,n) sum+=a[i];
	rep(i,sum+1) dp[i]=-1;
	dp[0]=0;
	rep(i,n){
		for(int x=sum/a[i]*a[i];x>=a[i];x-=a[i]){
			if(dp[x-a[i]]>=0) dp[x]=max(dp[x],dp[x-a[i]]+1);
		}
	}
	int ret=0,s=1;
	while(s<=sum){
		ret=max(ret,dp[s]);
//		printf("dp[%d]=%d\n",s,dp[s]);
		s*=2;
	}
	return ret;
}
int main(){
	p2[0]=1;
	rep(i,8) p2[i+1]=p2[i]*2;
	while(true){
		int N,a[1000];
		cin>>N;
		if(N==0) break;
		rep(i,N) cin>>a[i];
		int ans=1;
		for(int p=1;p<=500;p++){
			vector<int> vc;
			bool ok=false;
			rep(i,N) if(a[i]%p==0){
				rep(j,9) if(p2[j]==a[i]/p){
					vc.pb(p2[j]);
					if(j==0) ok=true;
				}
			}
			if(ok) ans=max(ans,solve(vc));
		}
		cout<<ans<<endl;
	}
}