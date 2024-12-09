#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
 
int main(){
  int n;
  cin >> n;
  ll a[n];
  for(int i = 0; i < n; i++)  cin >> a[i];
  ll ans = 0;
  for(int i = 0; i < 61; i++){
    ll cnt = 0;
    for(int j = 0; j < n; j++)  cnt += ((a[j]>>i)&1);
    ans += (1ll<<i)%mod * cnt % mod * (n-cnt);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}