#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t) {
    string s;
    cin >> s;
    vector<int> a(3);
    a[0] = -1;
    a[1] = -1;
    a[2] = -1;
    int ans = INF;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        a[0] = i;
      } else if (s[i] == '2') {
        a[1] = i;
      } else if (s[i] == '3') {
        a[2] = i;
      }
      if (a[0] >= 0 && a[1] >= 0 && a[2] >= 0) {
        int x = max(max(a[0], a[1]), a[2]) - min(min(a[2], a[1]), a[0]) + 1;
        ans = min(ans, x);
      }
    }
    if (ans == INF)
      cout << 0 << "\n";
    else
      cout << ans << "\n";
    t--;
  }
  return 0;
}
