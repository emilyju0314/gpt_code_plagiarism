#include <bits/stdc++.h>
using namespace std;
void Rd(int &res) {
  res = 0;
  char p;
  while (p = getchar(), p < '0')
    ;
  do {
    res = (res * 10) + (p ^ 48);
  } while (p = getchar(), p >= '0');
}
map<long long, int> mp[66];
map<long long, int>::iterator it;
int stk[666], sz;
long long bin[233];
int SG(int x, int S) {
  it = mp[x].find(S);
  if (it != mp[x].end()) return (it->second);
  if (x == 0) return mp[x][S] = 0;
  for (int i = 1; i <= x; i++)
    if (!(S & bin[i])) SG(x - i, S | bin[i]);
  sz = 0;
  for (int i = 1; i <= x; i++)
    if (!(S & bin[i])) stk[sz++] = SG(x - i, S | bin[i]);
  sort(stk, stk + sz);
  sz = unique(stk, stk + sz) - stk;
  stk[sz] = 233;
  for (int i = 1; i <= sz; i++)
    if (stk[i - 1] + 1 != stk[i]) return mp[x][S] = stk[i - 1] + 1;
  return 233;
}
int main() {
  for (int i = 0; i < 62; i++) bin[i] = (1LL << i);
  int n, ans = 0;
  Rd(n);
  for (int i = 1, x; i <= n; i++) Rd(x), ans ^= SG(x, 0);
  puts(ans ? "NO" : "YES");
  return 0;
}
