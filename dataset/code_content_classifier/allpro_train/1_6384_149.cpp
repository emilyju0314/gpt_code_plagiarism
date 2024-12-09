#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

struct LargeCombination{
    vector<ll> inv,pre,comb;
    LargeCombination(int n,int mx){
        inv.resize(mx+1);
        pre.resize(mx+1);
        comb.resize(mx+1);
        inv[1]=1;
        pre[1]=n;
        comb[0]=1,comb[1]=n;
        for(int i=2;i<=mx;i++){
            inv[i]=mod-inv[mod%i]*(mod/i)%mod;
            pre[i]=((n-i+1)*inv[i])%mod;
            comb[i]=(comb[i-1]*pre[i])%mod;
        }
    }
    ll operator()(int k){
        return comb[k];
    }
};

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    LargeCombination comb(n*m-2,k-2);
    ll ans=n*m*(n*m-1)*(n+m)/6;
    ans%=mod;
    ans*=comb(k-2);
    ans%=mod;
    cout<<ans<<endl;
}
