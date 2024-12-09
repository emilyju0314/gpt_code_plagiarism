#include <bits/stdc++.h>
using namespace std;
bool imp = true;
void solve() {
  long long n = 0, m = 0, i = 0, j = 0, k = 0, c = 0, flag = 1, sum = 0;
  string s, t;
  cin >> n;
  cin >> s;
  if (n < 7) {
    cout << "No\n";
    return;
  }
  for (i = 0; i < n - 6; i++) {
    string a = s;
    if (a[i] == '?') a[i] = 'a';
    if (a[i + 1] == '?') a[i + 1] = 'b';
    if (a[i + 2] == '?') a[i + 2] = 'a';
    if (a[i + 3] == '?') a[i + 3] = 'c';
    if (a[i + 4] == '?') a[i + 4] = 'a';
    if (a[i + 5] == '?') a[i + 5] = 'b';
    if (a[i + 6] == '?') a[i + 6] = 'a';
    long long c = 0;
    for (j = 0; j < n - 6; j++) {
      string temp = a.substr(j, 7);
      if (temp.compare("abacaba") == 0) c++;
    }
    if (c == 1) {
      for (j = 0; j < n; j++)
        if (a[j] == '?') a[j] = 'z';
      cout << "Yes" << '\n';
      cout << a << '\n';
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "No" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  if (imp) cin >> t;
  long long j = t;
  while (t--) {
    solve();
  }
  return 0;
}
