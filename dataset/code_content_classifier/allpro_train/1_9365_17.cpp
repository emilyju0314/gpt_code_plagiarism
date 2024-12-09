#include <bits/stdc++.h>
using namespace std;
map<int, long long> f[100005];
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
int ne[100005], la[100005], he[100005], tot = 0, num[100005], v[100005],
                                        rot[100005];
bool bz[100005];
map<int, long long>::iterator i1, i2;
inline void lb(int x, int y) {
  ne[++tot] = he[x];
  la[he[x] = tot] = y;
}
inline void dg(int x) {
  rot[x] = x;
  for (register int ii = he[x]; ii; ii = ne[ii]) {
    dg(la[ii]);
    if (f[rot[la[ii]]].size() > f[rot[x]].size()) swap(rot[la[ii]], rot[x]);
    for (i1 = f[rot[la[ii]]].begin(); i1 != f[rot[la[ii]]].end(); i1++)
      f[rot[x]][i1->first] += i1->second;
  }
  f[rot[x]][num[x]] += v[x];
  i1 = f[rot[x]].find(num[x]);
  i1++;
  while (i1 != f[rot[x]].end())
    if (i1->second > v[x]) {
      i1->second -= v[x];
      break;
    } else {
      v[x] -= i1->second;
      i2 = i1;
      i1++;
      f[rot[x]].erase(i2);
    }
}
int main() {
  int n = read(), m = read(), k = read();
  for (register int i = 2; i <= n; ++i) {
    int x = read();
    lb(x, i);
  }
  for (register int i = 1; i <= m; ++i) {
    int x = read();
    num[x] = read(), v[x] = read();
  }
  dg(1);
  long long ans = 0;
  for (i1 = f[rot[1]].begin(); i1 != f[rot[1]].end(); i1++) ans += i1->second;
  printf("%lld", ans);
  return 0;
}
