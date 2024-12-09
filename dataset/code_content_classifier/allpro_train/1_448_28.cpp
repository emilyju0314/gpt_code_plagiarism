#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, ans[3005];
bool ok;
string name[3005];
map<string, int> f;
bool cmp(string a, string b) { return f[a] < f[b]; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    cin >> name[i];
    f[name[i]] = read();
  }
  sort(name + 1, name + n + 1, cmp);
  ok = 1;
  for (int i = 1; i <= n; i++) {
    if (f[name[i]] >= i) {
      ok = 0;
      break;
    }
    ans[i] = 10 * (i - f[name[i]]);
    for (int j = 1; j < i; j++)
      if (ans[j] >= ans[i]) ans[j] += 10;
  }
  if (ok)
    for (int i = 1; i <= n; i++) cout << name[i] << ' ' << ans[i] << endl;
  else
    puts("-1");
  return 0;
}
