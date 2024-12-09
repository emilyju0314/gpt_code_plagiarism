#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k, f[405], d[405], h[405], mg[4][24];
string pre[4], nxt[4], s[40], st, tp[4050];
bool cmp(string a, string b) {
  for (int i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] < b[i]) return 1;
    if (a[i] > b[i]) return 0;
  }
  return a.length() < b.length();
}
long long count(string x) {
  long long res = 0;
  for (int i = 0; i < x.length(); i++) {
    if (i + st.length() > x.length()) break;
    bool p = 1;
    for (int j = 0; j < st.length(); j++)
      if (x[i + j] != st[j]) p = 0;
    res += p;
  }
  return res;
}
long long calc() {
  int len = st.length();
  pre[0].clear();
  pre[1].clear();
  nxt[0].clear();
  nxt[1].clear();
  d[14] = h[14] = 0;
  d[15] = h[15] = 1;
  for (int i = 0; i < len - 1; i++)
    pre[0].push_back(s[14][i]), pre[1].push_back(s[15][i]);
  for (int i = 1; i < len; i++)
    nxt[0].push_back(s[14][s[14].length() - len + i]);
  for (int i = 1; i < len; i++)
    nxt[1].push_back(s[15][s[15].length() - len + i]);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) mg[j][i] = count(nxt[j] + pre[i]);
  f[14] = count(s[14]);
  f[15] = count(s[15]);
  for (int i = 16; i <= n; i++) {
    h[i] = h[i - 1];
    d[i] = d[i - 2];
    f[i] = f[i - 1] + f[i - 2];
    f[i] += mg[d[i]][h[i]];
    if (f[i] > 1e18) return f[i];
  }
  return f[n];
}
int main() {
  scanf("%d%lld%d", &n, &k, &m);
  s[0] = "0", s[1] = "1";
  for (int i = 2; i <= 15; i++) s[i] = s[i - 2] + s[i - 1];
  if (n <= 15) {
    for (int i = 0; i < s[n].length(); i++)
      for (int j = i; j < s[n].length(); j++) tp[i + 1].push_back(s[n][j]);
    sort(tp + 1, tp + s[n].length() + 1, cmp);
    for (int i = 0; i < min(m, (int)tp[k].length()); i++)
      printf("%c", tp[k][i]);
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    st.push_back('0');
    long long t = calc();
    if (t < k) {
      k -= t;
      st.pop_back();
      st.push_back('1');
    }
    if (k == 0) {
      for (int i = 0; i < st.length(); i++) printf("%c", st[i]);
      return 0;
    }
  }
  for (int i = 0; i < st.length(); i++) printf("%c", st[i]);
  return 0;
}
