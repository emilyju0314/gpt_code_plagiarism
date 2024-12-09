#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N], x1[N], x2[N], cnt[N];
bool mark[N];
inline void read_input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
}
inline void solve() {
  iota(x1, x1 + N, 0);
  fill(x2, x2 + N, 1);
  for (int i = 2; i < N; i++)
    if (!mark[i])
      for (int j = i; j < N; j += i) {
        int p = 0;
        mark[j] = true;
        while (x1[j] % i == 0) x1[j] /= i, p++;
        for (int x = 0; x < p % k; x++) x1[j] *= i;
        while (p++ % k) x2[j] = min(1LL * x2[j] * i, N - 1LL);
      }
}
inline void write_output() {
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += cnt[x2[a[i]]], cnt[x1[a[i]]]++;
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
