//  Copyright © 2020 Kavish Lodha. All rights reserved.
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vll vector<long long>
#define mll map<long long,long long>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define pb push_back
#define prll pair<long long,long long>
typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define rep(i,a,n)   for(ll i=a; i<n; i++)
#define rrep(i,a,n)  for(ll i=n-1; i>=a; i--)
typedef map<string,ll> msl;
#define all(con) con.begin(),con.end()
#define done(x) {cout << x << endl;return;}
#define sz(x) ((long long)x.size())
#define trav(a,x) for(auto &a:x)
const ll mx=300005;
const ll mod=1e9 + 7;
const ld PI = 3.141592653589793238460;
//DEBUG FUNCTIONS START
#define cerr cout
void __print(ll x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
//#define deb(x...) cerr << "[" << #x << "] = "; _print(x)
#define deb(x...)  _print(x)
#else
#define deb(x...)
#endif
// DEBUG FUNCTIONS END
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rng(0,1000000000);
// ll x=rng(mt);
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll extgcd(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isPrime(ll n){
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
bool isPowerOfTwo(ll n) { 
   if(n==0) 
   return false; 
   return ((ll)ceil(log2(n)) == (ll)floor(log2(n))); 
}
ll powm(ll a,ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
ll divide(ll a,ll b) {
  return (a % mod) * powm(b, mod - 2) % mod;
}
ll mul(ll a,ll b) {
  return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
  return (a % mod + b % mod) % mod;
}
ll Totfun(ll n){
    ll z=n;
    if(n%2==0){
        while(n%2==0){
            n/=2;
        }
        z/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        if(isPrime(i)&&n%i==0){
          while(n%i==0){
            n/=i;
          }
        z-=z/i;  
        }
    }
    if(n>1){
        z-=z/n;
    }
    return z;
}
ll d=575;
ll fact[mx];
ll nCr(ll n,ll r){
    if(r>n||r<0) return 0;
    ll z=fact[n];
    z=mul(z,powm(fact[n-r],mod-2));
    z=mul(z,powm(fact[r],mod-2));
    return z;
}
/*
fact[0]=1;
rep(i,1,mx){
 fact[i]=mul(i,fact[i-1]);
}
*/
/*
vll a[mx];
ll l[mx],d[mx];
void dfs(ll x,ll y){
   l[x]=1; d[x]=y;
   for(ll i:a[x])
   if(!l[i])
   dfs(i,y+1);
}
void bfs(ll x){
    queue<ll> q;
    q.push(x);
    l[x]=1;
    d[x]=0;
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        for(ll i : a[cur]){
            if(1-l[i]){
                q.push(i);
                d[i]=d[cur]+1;
                l[i]=1;
            }
        }
    }
}
*/
 /*matrix exponential
 ll n;
   ll d;
   cin>>n;
   ll ans[2]={0,1};
   ll a[2][2],tmp[2][2];
   a[0][0]=0;
   a[0][1]=1;
   a[1][0]=1;
   a[1][1]=1;
   while(n>0){
       if(n%2){
           d=ans[0];
           ans[0]=(d*a[0][0]+a[1][0]*ans[1])%mod;
           ans[1]=(d*a[0][1]+a[1][1]*ans[1])%mod;
       }
       tmp[0][0]=(a[0][0]*a[0][0]+a[0][1]*a[1][0]); 
       tmp[0][1]=(a[0][0]*a[0][1]+a[0][1]*a[1][1]); 
       tmp[1][0]=(a[1][0]*a[0][0]+a[1][1]*a[1][0]); 
       tmp[1][1]=(a[1][0]*a[0][1]+a[1][1]*a[1][1]); 
       rep(i,0,2){
           rep(j,0,2) a[i][j]=tmp[i][j]%mod;
       }
       n/=2;
   }
   cout<<ans[0];
 */
bool cmp(vll a, vll b){
    if(a[0]/d!=b[0]/d) return a[0]<b[0];
    return a[1]>b[1];
}
ll f[mx];
void solve(){
    ll n,t,l,r;
    cin>>n>>t;
    ll a[n+1];
    rep(i,1,n+1) cin>>a[i];
    vector<vll> q(t,vll(3));
    vll ans(t);
    rep(i,0,t){
        rep(j,0,2) cin>>q[i][j];
        q[i][2]=i;
    }
    sort(q.begin(),q.end(),cmp);
    l=1;
    r=0;
    rep(i,0,t){
        ll ss=q[i][0],se=q[i][1];
        while(l>ss){
            l--;
            f[a[l]]++;
        }
        while(r<se){
            r++;
            f[a[r]]++;
        }
        while(l<ss){
            f[a[l]]--;
            l++;
        }
        while(r>se){
            f[a[r]]--;
            r--;
        }
        ll x=0;
        rep(k,0,20){
            int j=ss+rng(mt)%(se-ss+1);
            if(2*f[a[j]]>se-ss+2){
                x=f[a[j]];
                break;
            }
        }
        ans[q[i][2]]=max(1,2*x+ss-se-1);
    } 
    rep(i,0,t) cout<<ans[i]<<"\n";
}

int main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   cout.tie(NULL);
   cout<<fixed<<setprecision(20);
   ll t = 1;
   //cin >> t;
   while (t--)
       solve();
   return 0;
}