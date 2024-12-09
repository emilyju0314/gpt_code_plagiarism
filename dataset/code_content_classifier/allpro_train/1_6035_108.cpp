#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5,mod=998244353;
ll dp[N];
pair<ll,ll> a[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    dp[n]=1;
    stack< pair<ll,ll> > stk;
    stk.push({2e9,n});
    for(ll i=n-1;i>=0;i--){
        while(a[i].first+a[i].second > stk.top().first)stk.pop();
        dp[i] = (dp[i+1] + dp[stk.top().second] )%mod;
        stk.push({a[i].first,i});
    }
    cout<<dp[0];
}