#include <bits/stdc++.h>
using namespace std;
mt19937 twister(chrono::steady_clock().now().time_since_epoch().count());
const int mod = 1e9 + 7;
const int maxn = 1e7 + 88;
const int inf = 1e9 + 88;
const int logn = 22;
const int maxa = 3e6 + 88;
const char sgl[5] = {'a', 'e', 'i', 'o', 'u'};
const char sep = 'a' - 1;
int readint() {
  int cur;
  scanf("%d", &cur);
  return cur;
}
int umn(int a, int b) { return (1ll * a * b) % mod; }
void maxi(int &a, int b) { a = max(a, b); }
void mini(int &a, int b) { a = min(a, b); }
int rnd(int l, int r) { return abs((int)twister()) % (r - l + 1) + l; }
int n;
long long bad;
int p[maxn], pr[maxn], phi[maxn], sum[maxn], cnt[maxn];
void calc() {
  int i, j;
  for (i = 2; i <= n; i++) phi[i] = i;
  for (i = 2; i <= n; i++)
    if (!p[i])
      for (j = i; j <= n; j += i) {
        cnt[j]++;
        if (!p[j]) p[j] = i;
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
  for (i = 2; i <= n; i++)
    sum[i] = sum[i - 1] + (2 * i <= n && p[i] == i ? 1 : 0);
  long long cur = 1;
  for (i = 2; i <= n; i++)
    if (i * 2 > n && p[i] == i) cur++;
  bad += (cur) * (cur - 1) / 2;
  bad += (cur) * (n - cur);
}
long long find1() {
  long long res = 0;
  for (int i = 2; i <= n; i++) res += i - phi[i] - 1;
  return res;
}
long long find2() {
  long long res = 0;
  int i, j;
  long long cur = 0;
  for (i = 2; i <= n; i++)
    if (p[i] != i)
      res += phi[i] - (cur - cnt[i] + 1);
    else
      cur++;
  for (i = 2; i <= n; i++) pr[p[i]]++;
  for (i = 2; i <= n; i++) pr[i] += pr[i - 1];
  cur = 0;
  for (i = 2; 2 * i <= n; i++)
    if (p[i] == i) {
      res += pr[n / i];
      for (j = i; j <= n; j += i)
        if (p[j] <= n / i) res--;
    }
  for (i = 2; 2 * i <= n; i++)
    if (p[i] == i) cur += sum[n / i] - (n / i >= i ? 1 : 0);
  cur /= 2;
  return res - cur;
}
void solve() {
  n = readint();
  calc();
  long long cnt1 = find1();
  long long cnt2 = find2();
  long long cnt3 = 1ll * n * (n - 1) / 2 - cnt1 - cnt2 - bad;
  long long ans = cnt1 + cnt2 * 2 + cnt3 * 3;
  printf("%I64d", ans);
}
int main() {
  solve();
  return 0;
}
