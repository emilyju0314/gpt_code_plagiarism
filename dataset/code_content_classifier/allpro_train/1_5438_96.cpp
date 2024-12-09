#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const ll P=1000000007;
const int MAXN=4000+7;
ll n,k,dp[MAXN];
ll qPow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%P;
		x=x*x%P; y>>=1;
	}
	return res%P;
}
int main(){
	cin>>n>>k;
	dp[0]=1ll;
	for(register ll i=1;i<n;i++){
		for(register ll j=i;j>=1;j--){
			dp[j]=(dp[j-1]+dp[j+1])%P;
		}
		dp[0]=dp[1];
	}
	ll ans=(dp[n-k]*qPow(2ll,max(0ll,n-k-1)))%P;
	cout<<ans<<endl;
	return 0;
}