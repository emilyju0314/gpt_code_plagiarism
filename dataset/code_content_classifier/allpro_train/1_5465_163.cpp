#include <bits/stdc++.h>
using namespace std;
int S[30], T[30], P[30];
void addr(string s, int* v) {
  for (int i = 0; i < s.size(); i++) {
    v[s[i] - 'a']++;
  }
}
void solve(void) {
  memset(S, 0, sizeof(S));
  memset(T, 0, sizeof(T));
  memset(P, 0, sizeof(P));
  string s, t, p;
  cin >> s;
  cin >> t;
  cin >> p;
  addr(s, S);
  addr(t, T);
  addr(p, P);
  for (int i = 0; i < 26; i++) {
    if (S[i] > T[i]) {
      cout << "NO\n";
      return;
    }
  }
  int pos = 0, x = 0;
  while (x < t.size()) {
    if (s[pos] == t[x]) {
      pos++;
      if (pos == s.size()) break;
    }
    x++;
  }
  if (pos < s.size()) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (S[i] < T[i] && P[i] < T[i] - S[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
