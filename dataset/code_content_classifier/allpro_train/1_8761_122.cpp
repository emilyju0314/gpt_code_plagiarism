#include <bits/stdc++.h>
using namespace std;
string s;
int a, b, c, i, k, n;
int main() {
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) {
    if (s[i] == '0') a++;
    if (s[i] == '1') b++;
    if (s[i] == '?') c++;
  }
  vector<string> ans;
  if (n & 1) {
    if (a + c > b) ans.push_back("00");
    if (b + c > a + 1) ans.push_back("11");
  } else {
    if (a + c > b + 1) ans.push_back("00");
    if (b + c > a + 1) ans.push_back("11");
  }
  k = n >> 1;
  if (a + c >= k && a <= k) {
    int n0 = k - a;
    int n1 = c - n0;
    if ((s[n - 1] == '?' && n0) || s[n - 1] == '0') ans.push_back("10");
    if ((s[n - 1] == '?' && n1) || s[n - 1] == '1') ans.push_back("01");
  }
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
