#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;


ll powmod(ll n,ll k, ll mod){
    ll ret=1;
    while(k){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}

int P;
map<int,int> mp;
ll solve(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll x;
    cin>>x;
    ll res=1;
    for(auto q : mp){
        int p=q.first, m=q.second;
        ll tmp=P-1;
        int mi=m;
        rep(i,m){
            tmp/=p;
            rep(j,n){
                if(powmod(a[j],tmp,P)!=1)mi=min(i,mi);
            }
        }
        res*=powmod(p,mi,P);
    }
    ll ret=(P-1)/res;
    if(powmod(x,ret,P)==1){
        return 1;
    }
    else return 0;
}

int main(){
    ll t;
    cin>>P>>t;
    ll tmp=P-1;
    REP(i,2,1000000){
        if(tmp%i==0){
            while(tmp%i==0){
                mp[i]++;
                tmp/=i;
            }
        }
    }
    if(tmp>1)mp[tmp]++;
    rep(i,t){
        cout<<solve()<<endl;
    }
    return 0;
}
