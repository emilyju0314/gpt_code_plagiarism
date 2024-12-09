#include <bits/stdc++.h>
const int md = 1e9 + 7;
const int Inf = 1e9;
const long long Inf64 = 1e18;
const int MaxN = 2e3 + 100;
const int LogN = 20;
const int MaxM = 2e5 + 10;
const double eps = 1e-3;
const int dx[8] = {0, 1, 0, -1, -1, 1, -2, -2};
const int dy[8] = {1, 0, -1, 0, -2, -2, 1, -1};
const int ddx[4] = {1, 1, -1, -1};
const int ddy[4] = {1, -1, 1, -1};
const double Pi = acos(-1);
using namespace std;
template <typename T>
istream &operator>>(istream &in, pair<T, T> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, pair<T, T> a) {
  out << a.first << ' ' << a.second;
  return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &Mt) {
  for (T &a : Mt) in >> a;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> Mt) {
  for (int i = 0; i < (int)Mt.size(); i++) {
    out << Mt[i];
    if (i != (int)Mt.size()) out << ' ';
  }
  out << '\n';
  return out;
}
inline int Mod(int &a, int m = md) {
  while (a >= m) a -= m;
  return a;
}
inline int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}
inline int gcdex(int a, int mod = md) {
  int g = mod, r = a, x = 0, y = 1;
  while (r != 0) {
    int q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return x < 0 ? x + mod : x;
}
inline int binpow(int a, int n, int m = md) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= m;
    }
    a *= a;
    a %= m;
    n >>= 1;
  }
  return res % md;
}
vector<int> Ans;
vector<int> Gr[MaxN];
int Mt[MaxN];
vector<int> dfs(int v, int p = -1) {
  vector<int> Res;
  for (int to : Gr[v]) {
    if (to == p) continue;
    vector<int> t = dfs(to, v);
    for (int k : t) {
      Res.push_back(k);
    }
  }
  if ((int)Res.size() < Mt[v]) {
    cout << "NO";
    exit(0);
  }
  Res.insert(Res.begin() + Mt[v], v);
  return Res;
}
signed main() {
  {
    int N;
    cin >> N;
    int Root;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      Mt[i] = b;
      if (a == 0) {
        Root = i;
        continue;
      }
      a--;
      Gr[a].push_back(i);
      Gr[i].push_back(a);
    }
    vector<int> Kt = dfs(Root);
    Ans.assign(N, 0);
    for (int i = 0; i < N; i++) {
      Ans[Kt[i]] = i + 1;
    }
    cout << "YES" << '\n';
    cout << Ans;
  }
END:
  return 0;
}
