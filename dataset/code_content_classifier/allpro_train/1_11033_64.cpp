#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 3e5 + 4;
const int INF = 1e9;
bool IsPrime[maxn];
vector<int> Primes;
long long fact[maxn];
map<int, long long> cnt;
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < maxn; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
}
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  long long res = pw(a, b / 2);
  res = res * res;
  res %= MOD;
  if (b % 2 == 0)
    return res;
  else {
    res *= a;
    res %= MOD;
    return res;
  }
}
long long C(long long a, long long b) {
  long long c = fact[a] * fact[b - a];
  c %= MOD;
  long long res = fact[b] * pw(c, MOD - 2);
  res %= MOD;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  for (long long i = 2; i < maxn; i++) {
    if (!IsPrime[i]) {
      Primes.push_back(i);
      for (long long j = i * i; j < maxn; j += i) IsPrime[j] = true;
    }
  }
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < Primes.size() && Primes[j] * Primes[j] <= x; j++) {
      while (x % Primes[j] == 0) {
        cnt[Primes[j]]++;
        x /= Primes[j];
      }
    }
    if (x != 1) cnt[x]++;
  }
  long long ans = 1;
  for (map<int, long long>::iterator i = cnt.begin(); i != cnt.end(); i++) {
    ans *= C((*i).second, n + (*i).second - 1);
    ans %= MOD;
  }
  cout << ans;
  return 0;
}
