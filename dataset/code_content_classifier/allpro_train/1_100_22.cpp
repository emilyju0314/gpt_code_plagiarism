#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline char gc(void) {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  static char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -f;
  for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
inline void readstr(char *s) {
  do *s = gc();
  while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
  do *(++s) = gc();
  while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
  *s = 0;
  return;
}
inline void readch(char &x) {
  while (isspace(x = gc()))
    ;
}
char pf[100000], *o1 = pf, *o2 = pf + 100000;
template <class T>
inline void writeln(T x, char c = '\n') {
  if (x < 0)
    (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = 45 : *o1++ = 45),
        x = -x;
  static char s[15], *b;
  b = s;
  if (!x) *b++ = 48;
  for (; x; *b++ = x % 10 + 48, x /= 10)
    ;
  for (; b-- != s; (o1 == o2          ? fwrite(pf, 1, 100000, stdout),
                    *(o1 = pf)++ = *b : *o1++ = *b))
    ;
  (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = c : *o1++ = c);
}
template <class T>
inline void chkmax(T &x, const T y) {
  x > y ? x = x : x = y;
}
template <class T>
inline void chkmin(T &x, const T y) {
  x < y ? x = x : x = y;
}
const int N = 1e6 + 100;
int x[N], y[N], w[N], s[N], v[N];
bool in[N * 2];
vector<pair<int, int> > e[N];
vector<int> res;
int n, m;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie();
  cin >> n >> m;
  for (register int i = (1); i <= (m); i++) {
    cin >> x[i] >> y[i];
    w[i] = 1;
    s[x[i]]++;
    s[y[i]]++;
    e[max(x[i], y[i])].push_back(make_pair(min(x[i], y[i]), i));
  }
  for (register int i = (1); i <= (n); i++) {
    for (auto it : e[i]) {
      if (!v[it.first]) {
        v[it.first] = 1;
        w[it.second] = 0;
        s[i]--;
      }
      in[s[it.first]] = 1;
    }
    for (auto it : e[i]) {
      if (!in[s[i]]) break;
      s[i]++;
      v[it.first] = 0;
      w[it.second]++;
    }
    for (auto it : e[i]) in[s[it.first]] = 0;
  }
  for (register int i = (1); i <= (n); i++)
    if (v[i]) res.push_back(i);
  cout << int(res.size()) << '\n';
  for (auto it : res) cout << it << ' ';
  cout << '\n';
  for (register int i = (1); i <= (m); i++)
    cout << x[i] << ' ' << y[i] << ' ' << w[i] << '\n';
  return 0;
}
