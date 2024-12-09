#include <bits/stdc++.h>
const long long N = 500500;
const long long mod = 1000000007;
const long long INF = 1e+9;
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int xd[N];
void solve() {
  string s, t;
  cin >> s >> t;
  __f("s, t", s, t);
  for (int i = 1; i < t.size(); i++) {
    int pos = xd[i - 1];
    while (pos > 0 and t[i] != t[pos]) pos = xd[pos - 1];
    if (t[i] == t[pos]) pos++;
    xd[i] = pos;
  }
  int k = xd[t.size() - 1];
  __f("k", k);
  int uno_t = 0, cero_t = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      cero_t++;
    else
      uno_t++;
  }
  int cero_ac = 0, uno_ac = 0;
  int cero_ini = 0, uno_ini = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '0')
      cero_ini++;
    else
      uno_ini++;
    if (i < t.size() - k and t[i] == '0')
      cero_ac++;
    else if (i < t.size() - k and t[i] == '1')
      uno_ac++;
  }
  int tot = 0;
  while (1) {
    if (cero_ini > cero_t or uno_ini > uno_t) break;
    cero_ini += cero_ac;
    uno_ini += uno_ac;
    tot++;
  }
  cero_ini -= cero_ac;
  cero_t -= cero_ini;
  uno_ini -= uno_ac;
  uno_t -= uno_ini;
  if (tot == 0)
    cout << s << endl;
  else {
    cout << t;
    for (int i = 1; i < tot; i++) cout << t.substr(k);
    for (int i = 0; i < cero_t; i++) cout << "0";
    for (int i = 0; i < uno_t; i++) cout << "1";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  while (tc--) solve();
  return 0;
}
