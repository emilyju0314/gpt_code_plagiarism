#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005];
long long ans = 0;
void setup() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i] - 1;
  }
}
void xuly() {
  sort(a + 1, a + n + 1);
  int cnt = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != a[i + 1]) {
      int difference = a[i + 1] - a[i];
      if (difference > cnt) ans -= difference - cnt;
      cnt = max(cnt - difference, 0);
    }
    cnt++;
  }
  cout << ans;
}
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  setup();
  xuly();
  return 0;
}
