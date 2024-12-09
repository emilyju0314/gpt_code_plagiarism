#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) sort(a.begin(),a.end()); a.resize(unique(a.begin(),a.end())-a.begin());
#define print(s) for(auto u: s) cout<<u<<" "; cout<<"\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=998244353;
 
 
const int N=501;
ll dp[N][N][2], n;
vector<ll> a;
ll inc, id;
 
ll go(ll pos, ll diff, ll f){
    if(pos==n){
        if(f) return 1;
        return 0;
    }
    if(dp[pos][diff][f]!=-1)
        return dp[pos][diff][f];
    ll ans = go(pos+1,diff,f);
    if(a[pos]>0){
        ll val = a[pos];
        if(pos == id)
            ans = (ans + go(pos+1,diff+1,1))%mod;
        else{
            if(val<inc || (val==inc && pos<id))
                ans = (ans + go(pos+1,diff+1,f))%mod;
            else
                ans = (ans + go(pos+1,diff,f))%mod;
        }
    }
    else{
        if(diff-1 < 1)
            ans = (ans + go(pos+1,0,0))%mod;
        else
            ans = (ans + go(pos+1,diff-1,f))%mod;
    }
    return dp[pos][diff][f] = ans;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();
 
    cin>>n;
    for(ll i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='+'){
            ll num;
            cin>>num;
            a.pb(num);
        }
        else{
            a.pb(-1);
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]>0){
            inc = a[i]; id = i;
            memset(dp,-1,sizeof(dp));
            ll mul = go(0,0,0);
            ans = (ans + inc*mul%mod)%mod;
        }
    }
    cout<<ans;
 
 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}