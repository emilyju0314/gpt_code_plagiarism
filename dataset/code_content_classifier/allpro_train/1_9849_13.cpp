#include <bits/stdc++.h>
using namespace std;
void read(long long &x) { scanf("%lld", &x); }
void read(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void read(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void print(long long x) { printf("%lld ", x); }
void println(long long x) { printf("%lld\n", x); }
const long long N = 400000;
long long ans, sz, cur, len, calc, pos, mn;
string t, s, li[N + 10];
map<string, long long> v;
struct item {
  long long next[26], pos, cnt;
} st[333333];
void f() {
  if (s.size() == 0) return;
  li[++sz] = s;
  long long ch = 1 - v[s], ch1 = 0, can;
  v[s] = 1;
  cur = 0;
  len = s.size();
  mn = len;
  for (long long i = 0; i < len; i++) {
    if (!st[cur].next[s[i] - 97]) st[cur].next[s[i] - 97] = ++calc;
    cur = st[cur].next[s[i] - 97];
    if (st[cur].cnt == 1 && !ch1) {
      ch1 = 1;
      pos = st[cur].pos;
      can = 1;
      if (li[pos].size() <= s.size()) {
        for (long long j = i; j < li[pos].size(); j++)
          if (li[pos][j] != s[j]) can = 0;
        if (can) mn = min(mn, i + 2 + len - (long long)li[pos].size());
      }
    }
    st[cur].pos = sz;
    st[cur].cnt += ch;
  }
  ans += mn;
}
int main() {
  while (getline(cin, t)) {
    ans++;
    for (long long i = 0; i < t.size(); i++)
      if (t[i] > 'z' || t[i] < 'a')
        f(), s = "", ans++;
      else
        s += t[i];
    f();
    s = "";
  }
  cout << ans;
}
