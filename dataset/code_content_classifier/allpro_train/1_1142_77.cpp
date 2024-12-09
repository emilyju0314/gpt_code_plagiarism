#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a1[n][2];
  memset(a1, 0, sizeof(a1));
  for (long long i = 0; i < n; i++) cin >> a1[i][0];
  int q;
  cin >> q;
  int a2[q + 2];
  memset(a2, 0, sizeof(a2));
  for (long long i = 1; i < q + 1; i++) {
    int s;
    cin >> s;
    if (s == 1) {
      int p, x;
      cin >> p >> x;
      a1[p - 1][0] = x;
      a1[p - 1][1] = i;
    } else {
      int x;
      cin >> x;
      if (a2[0] < x) {
        a2[i] = x;
      }
    }
  }
  int maxi = 0;
  for (int i = q; i >= 0; i--) {
    maxi = max(a2[i], maxi);
    a2[i] = maxi;
  }
  for (long long i = 0; i < n; i++) {
    int res = max(a1[i][0], a2[a1[i][1]]);
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
