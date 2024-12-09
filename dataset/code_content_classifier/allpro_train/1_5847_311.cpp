#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int p[4];
int cnt[MAXN];
void solve() {
  for (int i = 0; i < 4; i++) cin >> p[i];
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < 24; i++) {
    next_permutation(p, p + 4);
    for (int j = a; j <= b; j++) {
      int x = (((j % p[0]) % p[1]) % p[2]) % p[3];
      if (x == j) cnt[j]++;
    }
  }
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (cnt[i] >= 7) ans++;
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
