#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 4e5 + 3;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() {
  puts("Yes");
  exit(0);
}
void NO() {
  puts("NO");
  exit(0);
}
void No() {
  puts("No");
  exit(0);
}
void one() {
  puts("-1");
  exit(0);
}
long long n, k;
long long fac[20];
bool isluck(long long x) {
  while (x) {
    int k = x % 10;
    if (!(k == 4 || k == 7)) {
      return false;
    }
    x /= 10;
  }
  return true;
}
int used[20];
vector<int> prem(long long n, long long k) {
  vector<int> ans;
  k--;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (used[j]) continue;
      if (k < fac[n - i]) {
        ans.push_back(j);
        used[j] = 1;
        break;
      } else {
        k -= fac[n - i];
      }
    }
  }
  return ans;
}
vector<long long> g;
void is_ll(long long x) {
  if (x <= n) {
    g.push_back(x);
    is_ll(x * 10 + 4);
    is_ll(x * 10 + 7);
  }
}
void solve() {
  fac[0] = 1;
  for (int i = 1; i <= 15; i++) {
    fac[i] = fac[i - 1] * i;
  }
  scanf("%lld", &(n));
  scanf("%lld", &(k));
  if (n < 13 && k > fac[n]) {
    puts("-1");
    return;
  }
  long long N = min(n, 13LL);
  vector<int> val = prem(N, k);
  is_ll(4);
  is_ll(7);
  int ans = 0;
  int sur = n - N + 1;
  for (int i = 0; i < N; i++) {
    if (isluck(i + sur) && isluck(val[i] + sur - 1)) ans++;
  }
  for (int i = 0; i < g.size(); i++) {
    if (g[i] < sur) ans++;
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
