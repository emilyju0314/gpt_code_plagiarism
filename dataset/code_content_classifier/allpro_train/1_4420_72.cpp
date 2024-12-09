#include <bits/stdc++.h>
using namespace std;
const int MX = 2e7 + 5;
int N, M, K;
int arr[MX], cnt[MX];
bool is[MX];
int a[400000];
int gcd(int a, int b) {
  while (a && b) {
    if (a >= b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int pw(int x, int p) {
  if (p == 0) return 1;
  int ret = pw(x, p >> 1);
  ret *= ret;
  if (p & 1) ret *= x;
  return ret;
}
int main() {
  int g = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    arr[x]++;
    g = gcd(g, x);
    a[i] = x;
  }
  map<int, int> fact;
  int gg = g;
  for (long long i = 2; i * i <= g; i++) {
    if (g % i != 0) continue;
    while (g % i == 0) fact[i]++, g /= i;
  }
  if (g > 1) fact[g]++;
  int ans = N;
  map<int, int>::iterator it = fact.begin();
  while (it != fact.end()) {
    int cur = 0;
    for (int j = 1; j <= N; j++) {
      int x = a[j] / pw(it->first, it->second);
      if (x % it->first) {
        ++cur;
      }
    }
    ans = min(ans, cur);
    it++;
  }
  int ans2 = N;
  for (int i = 2; i <= MX - 5; i++) {
    if (is[i]) continue;
    cnt[i] += arr[i];
    for (int j = i + i; j <= MX - 5; j += i) is[j] = 1, cnt[i] += arr[j];
    if (cnt[i] == N) continue;
    ans2 = min(ans2, N - cnt[i]);
  }
  ans = min(ans2, ans);
  if (ans == N) ans = -1;
  cout << ans;
  return 0;
}
