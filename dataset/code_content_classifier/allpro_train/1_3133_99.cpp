#include <bits/stdc++.h>
using namespace std;
template <class T>
void smin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void smax(T &a, T b) {
  a = max(a, b);
}
template <class T>
T min(vector<T> &a) {
  return *min_element(a.begin(), a.end());
}
template <class T>
T max(vector<T> &a) {
  return *max_element(a.begin(), a.end());
}
template <class T>
void print(vector<T> &a, string sep) {
  for (T el : a) cout << el << sep;
  cout << endl;
}
long long MOD = 998244353;
long long pow(long long n, long long k) {
  long long ans = 1;
  while (k > 0) {
    if (k % 2 == 1) {
      ans = (ans * n) % MOD;
    }
    n = (n * n) % MOD;
    k /= 2;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ;
  sort(a.begin(), a.end());
  long long Q = pow(n, MOD - 2);
  vector<long long> Ps(n);
  vector<long long> dp(n);
  dp[0] = a[0] % MOD;
  for (int i = 1; i < n; i++) {
    dp[i] = (dp[i - 1] + a[i] + MOD) % MOD;
  }
  for (int i = 0; i < n - 1; i++) {
    long long ctr = 1;
    int window = n - i - 1;
    int j = i;
    while (j >= 0) {
      int r = j;
      int l = j - window;
      long long d = dp[r];
      if (l >= 0) {
        d = (d - dp[l] + MOD) % MOD;
      }
      Ps[i] = (Ps[i] + (d * ctr) % MOD + MOD) % MOD;
      ctr++;
      j -= window;
    }
    Ps[i] = (Ps[i] * pow(n, MOD - 2) + MOD) % MOD;
  }
  Ps.pop_back();
  reverse(Ps.begin(), Ps.end());
  Ps.push_back(0);
  print(Ps, " ");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
