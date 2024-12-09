#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = 998244353;
int sum(int a, int b) {
  int s = a + b;
  if (s >= mod) s -= mod;
  return s;
}
int sub(int a, int b) {
  int s = a - b;
  if (s < 0) s += mod;
  return s;
}
int mult(int a, int b) { return (1LL * a * b) % mod; }
const int maxN = (int)1e6 + 100;
int a[maxN];
int k;
int fact[maxN];
int inv[maxN];
int invfact[maxN];
int num[maxN];
int cnk(int a, int b) {
  if (a < b) return 0;
  return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
void init() {
  fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
  for (int i = 2; i < maxN; i++) {
    fact[i] = mult(fact[i - 1], i);
    inv[i] = mult(inv[mod % i], mod - mod / i);
    invfact[i] = mult(invfact[i - 1], inv[i]);
  }
}
int add_val[maxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  cin >> k;
  int S = 0;
  int S_res = 0;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    S += a[i];
    int res = a[i] % k;
    S_res += res;
    add_val[res + 1] += k;
  }
  for (int i = 0; i < k; i++) {
    num[a[i]]++;
  }
  for (int i = 1; i <= k; i++) num[i] += num[i - 1];
  bool fnd = false;
  int ans = 0;
  for (int moves = 1; moves < k; moves++) {
    if (num[moves - 1] >= moves + 1) {
      fnd = true;
      break;
    }
    int vals = moves - num[moves - 1];
    ans = sum(ans, cnk(vals + k - 1, vals));
  }
  if (fnd) {
    cout << sum(ans, 1);
    return 0;
  }
  int total = 0;
  for (int res = 0; res < k; res++) {
    if (res > 0) add_val[res] += add_val[res - 1];
    int have = (S - S_res - add_val[res] + res * k) / k;
    total = sum(total, cnk(have + k - 1, k - 1));
  }
  cout << total;
  return 0;
}
