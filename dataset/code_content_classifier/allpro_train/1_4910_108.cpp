#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
		ch[i]--;
	}
	ll ru[200010]={};
	for(ll i=0;i<n;i++){
		ru[i+1]=ru[i]+ch[i];
	}
	for(ll i=0;i<=n;i++){
		ru[i]%=k;
	}
	map<ll,ll>cnt;
	ll ans=0;
	for(ll i=0;i<=n;i++){
		if(i>=k){
			cnt[ru[i-k]]--;
		}
		ll now=ru[i];
		ans+=cnt[now];
		cnt[now]++;
	}
	cout <<ans;
	// your code goes here
	return 0;
}