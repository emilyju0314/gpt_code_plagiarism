#include <bits/stdc++.h>
using namespace std;
const int N = 2e4;
int f2[N], f3[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  f2[n - 2] = 1;
  f3[n - 3] = 1;
  for (int i = n - 4; i >= 0; i--) {
    if (f3[i + 2]) f2[i] = 1;
    if (f2[i + 2] && (s[i] != s[i + 2] || s[i + 1] != s[i + 3])) f2[i] = 1;
    if (f2[i + 3]) f3[i] = 1;
    if (i + 5 < n && f3[i + 3] &&
        (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5]))
      f3[i] = 1;
  }
  set<string> Set;
  for (int i = 5; i < n - 1; i++) {
    string s1;
    s1 += s[i];
    s1 += s[i + 1];
    if (f2[i]) Set.insert(s1);
    if (i == n - 2) continue;
    string s2 = s1 + s[i + 2];
    if (f3[i]) Set.insert(s2);
  }
  cout << Set.size() << "\n";
  for (auto x : Set) cout << x << "\n";
}
