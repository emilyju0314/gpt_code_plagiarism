#include <bits/stdc++.h>
using namespace std;
long long pw(long long b, long long r, long long md) {
  long long ans = 1;
  while (r) {
    if (r & 1) ans = (ans * b) % md;
    b = (b * b) % md;
    r >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string ans;
    string s;
    cin >> s;
    long long n = s.length();
    long long p1 = 0, p2 = n - 1;
    while (p1 < p2) {
      if (s[p1] == s[p2]) {
        ans.push_back(s[p1]);
        p1++;
        p2--;
      } else
        break;
    }
    if (p1 >= p2)
      cout << s << '\n';
    else {
      string rev = s.substr(p1, p2 - p1 + 1);
      reverse(rev.begin(), rev.end());
      string a = s.substr(p1, p2 - p1 + 1) + '_' + rev;
      long long pref[a.length() + 1];
      memset(pref, 0, sizeof pref);
      long long l = 0;
      for (int i = 1; i < a.length();) {
        if (a[i] == a[l])
          pref[i++] = ++l;
        else {
          if (l == 0)
            i++;
          else {
            l = pref[l - 1];
          }
        }
      }
      long long mxlen = pref[a.length() - 1];
      rev = s.substr(p1, p2 - p1 + 1);
      reverse(rev.begin(), rev.end());
      a = rev;
      reverse(rev.begin(), rev.end());
      a = a + '_' + rev;
      l = 0;
      memset(pref, 0, sizeof pref);
      for (int i = 1; i < a.length();) {
        if (a[i] == a[l])
          pref[i++] = ++l;
        else {
          if (l == 0)
            i++;
          else {
            l = pref[l - 1];
          }
        }
      }
      rev = ans;
      reverse(rev.begin(), rev.end());
      long long mxlen2 = pref[a.length() - 1];
      if (mxlen > mxlen2) {
        for (int i = 0; i < mxlen; i++) ans.push_back(s[p1 + i]);
      } else {
        for (int i = 0; i < mxlen2; i++) ans.push_back(s[p2 - i]);
      }
      ans = ans + rev;
      cout << ans << '\n';
    }
  }
  return 0;
}
