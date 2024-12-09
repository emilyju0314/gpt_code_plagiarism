#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const ll inf = 3010;
bool sieve[maxn];
vector<ll> primes;
vector<ll> nums;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll x = 1;
  vector<ll> counts;
  int i = 0;
  for (int q = 0; q < 22; q++) {
    int j = i;
    ll cur = 1;
    const ll BOUND = 1e18;
    while (1) {
      if (cur > (BOUND / nums[i])) {
        break;
      }
      cur *= nums[i++];
    }
    cout << "? " << cur << endl;
    ll g;
    cin >> g;
    for (int k = j; k < i; k++) {
      ll pw = 0;
      ll base = primes[k];
      ll tmp = 1;
      while (g % tmp == 0) {
        pw++;
        tmp *= base;
      }
      pw--;
      if (pw > 0) {
        counts.push_back(pw);
      }
    }
    x *= g;
  }
  ll res = 1;
  for (ll x : counts) {
    res *= (x + 1);
  }
  cout << "! " << max(res + 7, res * 2) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int N = 1e6;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= N; j += i) {
        sieve[j] = true;
      }
    }
  }
  for (ll p : primes) {
    ll x = p;
    while (1) {
      if (x > inf / p) {
        break;
      }
      x *= p;
    }
    nums.push_back(x);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
