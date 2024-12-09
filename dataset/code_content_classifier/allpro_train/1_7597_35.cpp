#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long int ll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define MOD 1000003

ll modpow(ll a, ll n, ll m){
  ll tmp = a, val = 1;
  while(n){
    if(n % 2) val = val * tmp % m;
    tmp = tmp * tmp % m;
    n >>= 1;
  }
  return val;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
  ll Q;
  cin >> Q;
  ll x[Q], d[Q], n[Q];
  rep(i, Q) scanf("%lld %lld %lld", x+i, d+i, n+i);

  vector<ll> fact(1, 1);
  rep(i, 2*MOD) fact.push_back(fact[i] * (i + 1) % MOD);

  rep(i, Q){
    ll ans;
    if(d[i] == 0){
      ans = modpow(x[i], n[i], MOD);
    }
    else{
      ll xdinv = x[i] * modinv(d[i], MOD) % MOD;
      if((xdinv + n[i]) > MOD){
        ans = 0;
      }
      else{
        ans = modpow(d[i], n[i], MOD) * fact[xdinv+n[i]-1] * modinv(fact[xdinv-1], MOD) % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
