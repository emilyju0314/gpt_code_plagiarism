#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INF64 = 1e18;
const int MOD = 1000000007;
const int N = 20002;
int n, M, T;
int t[N];
int ans[N];
int used[N];
int main() {
  scanf("%d%d%d", &n, &M, &T);
  for (int i = 0; i < int(n); i++) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    t[i] = h * 3600 + m * 60 + s;
  }
  bool ok = false;
  int cur = 1;
  int u = 0;
  int l = 0;
  for (int i = 0; i < int(n); i++) {
    while (l < i && t[l] + T - 1 < t[i]) {
      used[ans[l]]--;
      if (used[ans[l]] == 0) {
        u--;
      }
      l++;
    }
    if (u == M) {
      ans[i] = ans[i - 1];
    } else {
      ans[i] = cur++;
      u++;
    }
    used[ans[i]]++;
    if (u == M) ok = true;
  }
  if (!ok) {
    puts("No solution");
  } else {
    printf("%d\n", cur - 1);
    for (int i = 0; i < int(n); i++) printf("%d\n", ans[i]);
  }
  return 0;
}
