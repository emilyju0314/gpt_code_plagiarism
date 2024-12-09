#include <bits/stdc++.h>
using namespace std;
int n, fre[150];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  int cnt = 0;
  for (auto &ele : s) {
    cnt += ((fre[ele]++) == 0);
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    fre[s[i]] = 0;
  if (cnt == 1) {
    cout << 1;
    return 0;
  }
  int l = 0, r = 0, ccnt = 1, ans = n;
  fre[s[0]] = 1;
  while (l < n) {
    while (r + 1 < n and ccnt < cnt) {
      r++;
      ccnt += ((fre[s[r]]++) == 0);
    }
    if (ccnt == cnt) ans = min(ans, r - l + 1);
    ccnt -= (fre[s[l++]]-- == 1);
  }
  cout << ans;
}
