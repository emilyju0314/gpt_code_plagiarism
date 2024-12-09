#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
void __die(int a) { printf("%d", (a * a) / (a + a)); }
struct tree {
  long long m[300000 + 300000];
  int n;
  void Init(int _n) {
    n = _n;
    for (int(i) = (1); (i) <= (n + n - 1); ++(i)) m[i] = 0;
  }
  void Add(int i, int j, int val) {
    {
      if (!(1 <= i && i <= j && j <= n)) {
        __never(39);
        cout.flush();
        cerr.flush();
        __die(0);
      }
    };
    i += n - 1;
    j += n - 1;
    while (i <= j) {
      if ((i & 1) == 1) m[i] += val;
      if ((j & 1) == 0) m[j] += val;
      i = (i + 1) >> 1;
      j = (j - 1) >> 1;
    }
  }
  long long get(int pos) {
    {
      if (!(1 <= pos && pos <= n)) {
        __never(50);
        cout.flush();
        cerr.flush();
        __die(0);
      }
    };
    pos += n - 1;
    long long res = m[pos];
    while (pos > 1) {
      pos = pos >> 1;
      res += m[pos];
    }
    return res;
  }
} tr;
int n, m;
int pos[300000];
int p[300000];
vector<pair<int, int> > qs[300000];
long long ans[300000];
long long all[300000];
void init() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void sol() {
  scanf("%d %d", &n, &m);
  for (int(i) = (1); (i) <= (n); ++(i)) scanf("%d", &p[i]);
  int a, b;
  for (int(i) = (1); (i) <= (m); ++(i)) {
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    qs[b].push_back(make_pair(a, i));
  }
  tr.Init(n);
  for (int(i) = (1); (i) <= (n); ++(i)) {
    int v = p[i];
    all[i] = all[i - 1];
    for (int j = v + v; j <= n; j += v)
      if (pos[j]) {
        tr.Add(pos[j], i - 1, 1);
        all[i]++;
      }
    for (int j = 1; j * j <= v; j++)
      if (v % j == 0 && v != j) {
        if (pos[j]) {
          tr.Add(pos[j], i - 1, 1);
          all[i]++;
        }
        if (j * j != v && pos[v / j]) {
          tr.Add(pos[v / j], i - 1, 1);
          all[i]++;
        }
      }
    pos[p[i]] = i;
    for (int(j) = (0); (j) <= ((int)((qs[i]).size()) - 1); ++(j)) {
      int be = qs[i][j].first;
      long long r = (i - be + 1) + all[i] - all[be - 1];
      if (be > 1) r -= tr.get(be - 1);
      ans[qs[i][j].second] = r;
    }
  }
  for (int(i) = (1); (i) <= (m); ++(i)) printf("%I64d\n", ans[i]);
}
int main() {
  sol();
  return 0;
}
