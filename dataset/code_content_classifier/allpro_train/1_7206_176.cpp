#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ct[N];
void solve() {
  int n, x, q;
  char c;
  cin >> n;
  int sqr = 0, rec = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ct[x]++;
  }
  for (int i = 1; i < N; i++) {
    sqr += ct[i] / 4;
    rec += ct[i] / 2;
  }
  cin >> q;
  while (q--) {
    cin >> c >> x;
    if (c == '-') {
      if (ct[x] % 4 == 0) sqr--;
      if (ct[x] % 2 == 0) rec--;
      ct[x]--;
    } else {
      if (ct[x] % 4 == 3) sqr++;
      if (ct[x] % 2 == 1) rec++;
      ct[x]++;
    }
    if (sqr >= 1 and rec >= 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
