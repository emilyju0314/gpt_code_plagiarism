#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const int maxn = 1e6 + 5;
int k;
int n;
string s, a, b;
int mp[256];
int mpc[256];
int used[256];
bool apply(char c, char d) {
  if (mp[c - 'a']) {
    if (char(mp[c - 'a'] + 'a' - 1) != d) {
      return false;
    }
    mpc[c - 'a']++;
    return true;
  }
  if (used[d - 'a']) {
    return false;
  }
  mp[c - 'a'] = d - 'a' + 1;
  used[d - 'a'] = 1;
  mpc[c - 'a']++;
  return true;
}
void undo(char c, char d) {
  if (--mpc[c - 'a'] == 0) {
    mp[c - 'a'] = 0;
    used[d - 'a'] = 0;
  }
}
bool dfs(int i, bool ea = true, bool eb = true) {
  if (i == n) {
    return true;
  }
  if (ea && eb) {
    for (char c = a[i]; c <= b[i]; c++) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else if (!ea && eb) {
    for (char c = 'a'; c <= b[i]; c++) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else if (ea && !eb) {
    for (char c = char('a' + k - 1); c >= a[i]; c--) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else {
    return true;
  }
}
void solve() {
  cin >> k;
  cin >> s >> a >> b;
  n = s.length();
  for (int i = 0; i < 27; i++) {
    mp[i] = mpc[i] = used[i] = 0;
  }
  if (dfs(0)) {
    cout << "YES\n";
    int ptr = 0;
    for (int i = 0; i < k; i++) {
      if (!mp[i]) {
        while (used[ptr]) ++ptr;
        used[ptr] = true;
        mp[i] = ptr + 1;
      }
      char c = char(mp[i] + 'a' - 1);
      cout << c;
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
