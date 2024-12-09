#include <bits/stdc++.h>
using namespace std;
int cnt1[200005], cnt2[200005];
int f(char c1, char c2, char c3, char c4) {
  int ret = 2;
  if (c1 == c2) ret--;
  if (c3 == c4) ret--;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, ans = 0;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (i = 0; i < ((int)s1.size() + 1) / 2; i++) {
    char c1 = s1[i];
    char c2 = s1[n - i - 1];
    char c3 = s2[i];
    char c4 = s2[n - i - 1];
    int ret = 3;
    if (i == n - i - 1) {
      if (c1 != c3) {
        ans++;
      }
      continue;
    }
    if (c3 == c4) {
      if (c1 != c2) ans++;
      continue;
    }
    ans += min(f(c3, c1, c4, c2), f(c3, c2, c4, c1));
  }
  cout << ans;
  return 0;
}
