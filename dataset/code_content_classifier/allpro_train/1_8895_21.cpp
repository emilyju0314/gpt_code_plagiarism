#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 5e5 + 5, maxa = 1 << 20, mod = 1e9 + 7;

int N, a[maxn], sx[maxn];

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N;
  for(int i = 1; i <= N; ++i){
    cin >> a[i];
    sx[i] = sx[i - 1] ^ a[i];
  }
  auto add = [&](int & x, int y)
  {
    x += y;
    if(x >= mod) x -= mod;
  };
  if(sx[N]){
    int x = 1, y = 0;
    for(int i = 1; i <= N; ++i){
      if(sx[i] == 0){
        add(x, y);
      }
      else if(sx[i] == sx[N]){
        add(y, x);
      }
    }
    cout << x;
  }
  else{
    vector<int> f(N + 5), sum(N + 5), x(maxa, 1), y(maxa), r(maxa);
    int ans = 1;
    for(int i = 1; i <= N; ++i){
      sum[i] = sum[i - 1] + (sx[i] == 0);
    }
    for(int i = 1; i <= N; ++i){
      if(sx[i]){
        (x[sx[i]] += y[sx[i]]*(sum[i]-sum[r[sx[i]]])%mod) %= mod;
        add(y[sx[i]], x[sx[i]]);
        r[sx[i]] = i;
      }
      else{
        if(i != N){
          ans = 2ll * ans % mod;
        }
      }
    }
    for(int i = 1; i < maxa; ++i)
      add(ans, y[i]);
    cout << ans;
  }
}
