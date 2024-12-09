#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int spf[100001];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < 100001; i++) spf[i] = i;
  for (int i = 4; i < 100001; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 100001; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < 100001; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}
vector<int> getFactorization(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
int findGCD(vector<long long int> v, int n) {
  int result = v[0];
  for (int i = 1; i < n; i++) result = gcd(v[i], result);
  return result;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  for (long long i = 0; i < k; i++) {
    s.push_back('a' + i);
  }
  string ans;
  long long a = n / k;
  long long b = a;
  while (a--) {
    for (long long int i = 0; i < k; i++) {
      ans.push_back(s[i]);
    }
  }
  for (long long int i = 0; i < n - b * k; i++) {
    ans.push_back(s[i]);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) solve();
  return 0;
}
