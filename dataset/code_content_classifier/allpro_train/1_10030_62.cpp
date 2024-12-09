#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
 
ll w[N],v[N];
map<ll,ll>dp;
int main()
{
    ll n,W;
    scanf("%lld%lld",&n,&W);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",w+i,v+i);
    }
    if(w[1]<=1e3){
        ll j;
        ll temp=min((w[1]+3)*n,W);
        for(int i=1;i<=n;i++){
            for(j=temp;j>=1;j--){
                if(j>=w[i])
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[temp]<<endl;
    }
    else{
        ll j;
        ll temp=min(W,(w[1]+3)*n);
        for(int i=1;i<=n;i++){
            for(j=temp;j>=w[1];j-=w[1]){
                if(j>=w[i])
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[temp]<<endl;
    }
    return 0;
}
