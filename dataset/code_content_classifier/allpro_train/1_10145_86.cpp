#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
string s, t;
int pos1[300100], pos2[300100], ans, now;
int main() {
  cin >> s;
  cin >> t;
  int ns = s.length();
  int nt = t.length();
  for (int i = 0; i < ns; i++) {
    if (s[i] == t[now]) {
      pos1[now] = i;
      now++;
    }
  }
  now = nt - 1;
  for (int i = ns - 1; i >= 0; i--) {
    if (s[i] == t[now]) {
      pos2[now] = i;
      now--;
    }
  }
  for (int i = 0; i < nt - 1; i++) {
    ans = max(ans, pos2[i + 1] - pos1[i] - 1);
  }
  ans = max(ans, pos2[0]);
  ans = max(ans, ns - pos1[nt - 1] - 1);
  cout << ans;
}
