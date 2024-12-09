#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); };
int dr[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dc[] = {1, 0, -1, 0, 1, -1, 1, -1};
int n, m, k, t;
long long a[200001];
int cnt[20];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 20; j++) {
      if (a[i] & (1 << j)) {
        cnt[j]++;
      }
    }
  }
  long long ans = 0;
  while (1) {
    long long res = 0;
    int mn = 1e9;
    for (int i = 0; i < 20; i++) {
      if (cnt[i] == 0) {
        continue;
      }
      res |= (1 << i);
      mn = min(mn, cnt[i]);
    }
    if (res == 0) break;
    for (int i = 0; i < 20; i++) {
      if (!cnt[i]) continue;
      cnt[i] -= mn;
    }
    ans += res * res * mn;
  }
  cout << ans << '\n';
  return 0;
}
