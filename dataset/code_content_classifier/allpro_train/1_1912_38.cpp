#include <bits/stdc++.h>
using namespace std;
struct InputReader {
  char buf[1000001];
  int p;
  inline InputReader() { p = 1000001; }
  inline void Flush() {
    p = 0;
    fread(buf, 1, 1000001, stdin);
  }
  inline char C() {
    if (p >= 1000001) Flush();
    return buf[p++];
  }
  inline char Readnum() {
    char ch = C();
    while (!isdigit(ch) && ch != '-') ch = C();
    return ch;
  }
  inline void Readalpha(char &c) {
    c = C();
    while (!isalpha(c)) c = C();
  }
  int operator()() {
    int ans = 0, fu = 1;
    char ch = Readnum();
    if (ch == '-') fu = -1, ch = C();
    while (ch >= '0' && ch <= '9') {
      ans = ans * 10 + ch - '0';
      ch = C();
    }
    return ans * fu;
  }
  long long Readll() {
    long long ans = 0LL, fu = 1LL;
    char ch = Readnum();
    if (ch == '-') fu = -1LL, ch = C();
    while (ch >= '0' && ch <= '9') {
      ans = ans * 10LL + ch - '0';
      ch = C();
    }
    return ans * fu;
  }
  inline void Readstring(string &x) {
    x.clear();
    char ch = C();
    while (!isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.') ch = C();
    while (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') {
      x += ch;
      ch = C();
    }
  }
  inline void Readchstring(char s[]) {
    int len = 0;
    char ch = C();
    while (!isdigit(ch) && !isalpha(ch)) ch = C();
    while (isdigit(ch) || isalpha(ch)) {
      s[len++] = ch;
      ch = C();
    }
    s[len] = '\0';
  }
  inline void Specialread(char &c) {
    c = C();
    while (!isdigit(c) && !isalpha(c) && c != '#' && c != '.' && c != '=' &&
           c != 'B')
      c = C();
  }
} In;
inline void Read(int &x) { x = In(); }
inline void Read(int &x, int &y) {
  x = In();
  y = In();
}
inline void Read(int &x1, int &x2, int &x3) {
  x1 = In();
  x2 = In();
  x3 = In();
}
inline void Read(int &x1, int &x2, int &x3, int &x4) {
  x1 = In();
  x2 = In();
  x3 = In();
  x4 = In();
}
inline void Read(long long &x) { x = In.Readll(); }
inline void Read(long long &x, long long &y) {
  x = In.Readll();
  y = In.Readll();
}
inline void Read(long long &x1, long long &x2, long long &x3) {
  x1 = In.Readll();
  x2 = In.Readll();
  x3 = In.Readll();
}
inline void Read(long long &x1, long long &x2, long long &x3, long long &x4) {
  x1 = In.Readll();
  x2 = In.Readll();
  x3 = In.Readll();
  x4 = In.Readll();
}
inline void FILEIO() {}
inline void FILEIO(string pname) {
  freopen((pname + ".in").c_str(), "r", stdin);
  freopen((pname + ".out").c_str(), "w", stdout);
}
void Printtime() {}
void END() {
  Printtime();
  exit(0);
}
template <typename T>
void END(T mes) {
  cout << mes << endl;
  END();
}
template <typename T>
void Print(T a[], int s, int t, char sp = ' ', char ed = '\n') {
  if (s > t) return;
  for (int i = s; i < t; i++) cout << a[i] << sp;
  cout << a[t] << ed;
  cout.flush();
}
template <typename T>
void Print(T a, int s = 0, int t = -1, char sp = ' ', char ed = '\n') {
  if (t == -1) t = a.size() - 1;
  for (int i = s; i <= t; i++) cout << a[i] << sp;
  cout << ed;
  cout.flush();
}
int n, k;
vector<int> e[300010];
int a[300010];
vector<int> cols[300010];
int color[300010];
void Readin() {
  Read(n, k);
  for (int(i) = 1; (i) <= (n); ++(i)) {
    Read(a[i]);
    cols[a[i]].push_back(i);
  }
  for (int(i) = 1; (i) <= (n - 1); ++(i)) {
    int a;
    Read(a);
    ;
    int b;
    Read(b);
    ;
    ;
    e[a].push_back(b);
    e[b].push_back(a);
  }
}
int up[300010][20], dep[300010];
void Lcadfs(int pos, int fa) {
  dep[pos] = dep[fa] + 1;
  up[pos][0] = fa;
  for (int(i) = 1; (i) <= (20 - 1); ++(i))
    up[pos][i] = up[up[pos][i - 1]][i - 1];
  for (auto v : e[pos]) {
    if (v == fa) continue;
    Lcadfs(v, pos);
  }
}
int Lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int(i) = (20) - 1; (i) >= 0; --(i)) {
    int v = up[a][i];
    if (dep[v] >= dep[b]) a = v;
  }
  if (a == b) return a;
  for (int(i) = (20) - 1; (i) >= 0; --(i)) {
    int u = up[a][i];
    int v = up[b][i];
    if (u != v) {
      a = u;
      b = v;
    }
  }
  a = up[a][0];
  b = up[b][0];
  assert(a == b);
  assert(a);
  return a;
}
int l[300010];
void Marklca() {
  memset(l, -1, sizeof(l));
  for (int(i) = 1; (i) <= (n); ++(i)) {
    int col = a[i];
    if (!col) continue;
    if (l[col] == -1)
      l[col] = i;
    else
      l[col] = Lca(l[col], i);
  }
  for (int(i) = 1; (i) <= (k); ++(i)) {
    if (a[l[i]] and a[l[i]] != i) END("0");
    a[l[i]] = i;
  }
}
int dp[300010][2];
int Dfs(int pos, int fa) {
  vector<pair<int, int> > cur;
  vector<int> val;
  for (auto v : e[pos]) {
    if (v == fa) continue;
    int c = Dfs(v, pos);
    if (c != 0) cur.push_back({c, v});
    if (c != -1 and c != 0) val.push_back(c);
  }
  sort(val.begin(), val.end());
  val.resize(unique(val.begin(), val.end()) - val.begin());
  if (val.size() > 1) END("0");
  if (a[pos] != 0 and !val.empty() and a[pos] != val[0]) END("0");
  if (a[pos] == 0 and cur.empty()) {
    dp[pos][0] = 1;
    dp[pos][1] = 0;
    return 0;
  }
  if (a[pos] == 0 and val.empty()) {
    dp[pos][0] = 1;
    for (auto [c, v] : cur) {
      dp[pos][0] = 1LL * dp[pos][0] * (dp[v][1] + dp[v][0]) % 998244353;
    }
    for (auto [c, v] : cur) {
      int tadd = dp[v][1];
      for (auto [c, w] : cur) {
        if (v == w) continue;
        tadd = 1LL * tadd * (dp[w][0] + dp[w][1]) % 998244353;
      }
      dp[pos][1] = (dp[pos][1] + tadd) % 998244353;
    }
    return -1;
  } else {
    dp[pos][0] = 0;
    dp[pos][1] = 1;
    for (auto [c, v] : cur) {
      if (c == -1) {
        dp[pos][1] = 1LL * dp[pos][1] * (dp[v][0] + dp[v][1]) % 998244353;
      } else {
        dp[pos][1] = 1LL * dp[pos][1] * dp[v][1] % 998244353;
      }
    }
    if (a[pos] == 0) return val[0];
    if (pos == l[a[pos]])
      return -1;
    else
      return a[pos];
  }
}
int main() {
  FILEIO();
  Readin();
  Lcadfs(1, 0);
  Marklca();
  Dfs(1, 0);
  cout << dp[1][1] << endl;
  END();
}
