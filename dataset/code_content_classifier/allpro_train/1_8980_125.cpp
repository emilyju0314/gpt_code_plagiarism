#import <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,ans=0;
    cin>>n; if(n==1)cout<<"0\n",exit(0);
    map<ll,ll> fac;

    for(ll i=2; n>1 && i*i<=n ;++i)if(n%i==0) fac[i]++,n/=i,i--;
    fac[n]++;

    for(auto x:fac){
        ll i;
        for(i=1;(i+1)*i/2 <= x.second;i++);
        ans+=i-1;
    }
    cout<<ans<<endl;
}
