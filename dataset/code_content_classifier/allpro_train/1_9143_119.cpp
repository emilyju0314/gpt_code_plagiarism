#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <class T>
inline bool fs(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
long long int sat(long long int n, long long int pos) {
  return n = n | (1LL << pos);
}
long long int reset(long long int N, long long int pos) {
  return N = N & ~(1LL << pos);
}
bool cak(long long int n, long long int pos) {
  return (bool)(n & (1LL << pos));
}
long long int binPow(long long int a, long long int q, long long int mud) {
  a %= mud;
  if (q == 0) return 1;
  return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}
pair<long long int, long long int> ex_clid(long long int a, long long int b) {
  if (b == 0) return pair<long long int, long long int>(1, 0);
  pair<long long int, long long int> d = ex_clid(b, a % b);
  return pair<long long int, long long int>(d.second,
                                            d.first - d.second * (a / b));
}
long long int mod_inv(long long int n, long long int md) {
  pair<long long int, long long int> d = ex_clid(n, md);
  return ((d.first % md) + md) % md;
}
template <class T>
double dif(T &a, T &b) {
  double ans = (a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second);
  return sqrt(ans);
}
int n, m, k, a, b;
vector<int> nod[1000000 + 5], bod[1000000 + 5];
bool mark[1000000 + 5];
vector<int> ans;
void dfs(int u) {
  mark[u] = true;
  ans.push_back(u);
  for (int i = 0; i < nod[u].size(); i++) {
    int v = nod[u][i];
    if (mark[v]) continue;
    dfs(v);
    ans.push_back(u);
  }
}
int main() {
  fs(n);
  fs(m);
  fs(k);
  for (int i = 0; i < m; i++) {
    fs(a);
    fs(b);
    nod[a].push_back(b);
    nod[b].push_back(a);
  }
  dfs(1);
  vector<int> num;
  int tot = (2 * n + (k - 1)) / k;
  int ln = ans.size();
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    if (cnt == ln) {
      bod[i].push_back(i);
      continue;
    }
    for (int j = 0; j < tot && cnt < ln; j++, cnt++) bod[i].push_back(ans[cnt]);
  }
  for (int i = 0; i < k; i++) {
    cout << bod[i].size();
    for (int j = 0; j < bod[i].size(); j++) cout << ' ' << bod[i][j];
    cout << endl;
  }
  return 0;
}
