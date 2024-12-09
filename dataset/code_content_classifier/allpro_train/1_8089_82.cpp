#include <bits/stdc++.h>
using namespace std;
string a[40];
int f[90000], s1[90000], s2[90000], v[90000], n;
map<string, int> u;
int score(string s) {
  int ans = 0, cur;
  for (int i = 0; i < s.size(); i++) ans += s[i] - 96;
  cur = 0;
  for (int i = 0; i < s.size(); i++) cur = max(cur, s[i] - 96);
  ans *= cur;
  for (int i = 1; i <= n; i++)
    if (a[i].find(s) != string::npos) ans++;
  return ans;
}
void dp(int x, string cur) {
  if (v[x]) return;
  v[x] = 1;
  int endit = 0;
  f[x] = 0;
  s1[x] = 0;
  s2[x] = 1000000000;
  for (int i = 1; i <= 26; i++) {
    string v = "";
    v += char(i + 96);
    v += cur;
    if (!u.count(v)) continue;
    endit = 1;
    int next = u[v], now = score(v);
    dp(next, v);
    if (f[next] == 0 && f[x] == 0) {
      f[x] = 1;
      s1[x] = now + s2[next];
      s2[x] = s1[next];
    } else if ((f[next] ^ 1) == f[x]) {
      int S1 = now + s2[next];
      int S2 = s1[next];
      if (S1 > s1[x] || S1 == s1[x] && S2 < s2[x]) {
        s1[x] = S1;
        s2[x] = S2;
      }
    }
  }
  for (int i = 1; i <= 26; i++) {
    string v = cur;
    v += char(i + 96);
    if (!u.count(v)) continue;
    endit = 1;
    int next = u[v], now = score(v);
    dp(next, v);
    if (f[next] == 0 && f[x] == 0) {
      f[x] = 1;
      s1[x] = now + s2[next];
      s2[x] = s1[next];
    } else if ((f[next] ^ 1) == f[x]) {
      int S1 = now + s2[next];
      int S2 = s1[next];
      if (S1 > s1[x] || S1 == s1[x] && S2 < s2[x]) {
        s1[x] = S1;
        s2[x] = S2;
      }
    }
  }
  if (endit == 0) {
    s1[x] = 0;
    s2[x] = 0;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  u.clear();
  int tot = 0;
  for (int i = 1; i <= n; i++)
    for (int x = 0; x < a[i].size(); x++) {
      string cur = "";
      for (int y = x; y < a[i].size(); y++) {
        cur += a[i][y];
        if (!u.count(cur)) u[cur] = ++tot;
      }
    }
  memset(v, 0, sizeof(v));
  int win = 0, S1 = 0, S2 = 1000000000;
  for (int i = 1; i <= 26; i++) {
    string v = "";
    v += char(i + 96);
    if (!u.count(v)) continue;
    int next = u[v], now = score(v);
    dp(next, v);
    if (f[next] == 0 && win == 0) {
      win = 1;
      S1 = s2[next] + now;
      S2 = s1[next];
    } else if ((f[next] ^ 1) == win)
      if (s2[next] + now > S1 || s2[next] + now == S1 && s1[next] < S2) {
        S1 = s2[next] + now;
        S2 = s1[next];
      }
  }
  if (win)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  cout << S1 << " " << S2 << endl;
  return 0;
}
