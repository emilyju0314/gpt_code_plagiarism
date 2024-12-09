#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5, V = 6e6 + 5, MOD1 = 666013, MOD2 = 1e9 + 7, Q = 1.1e6;
int n, m, bucket;
vector<int> p[N];
vector<pair<int, int>> qs[N];
int lst[V], v[N], ant[Q], lft[100], mp[V][8];
static void getp(int num, vector<int> &p) {
  int b, e;
  p.clear();
  while (num > 1) {
    b = lst[num], e = 0;
    while (lst[num] == b) {
      num /= lst[num];
      e ^= 1;
    }
    if (e) p.push_back(b);
  }
}
static inline char nextch() {
  const int BMAX = 4096;
  static char buff[BMAX];
  static int bp = BMAX;
  if (bp == BMAX) {
    fread(buff, 1, BMAX, stdin);
    bp = 0;
  }
  return buff[bp++];
}
static void get(int &val) {
  char ch;
  int sgn = 1;
  do {
    ch = nextch();
  } while ((ch < '0' || '9' < ch) && ch != '-');
  if (ch == '-') {
    sgn = -1;
    ch = nextch();
  }
  val = 0;
  do {
    val = val * 10 + (ch - '0');
    ch = nextch();
  } while ('0' <= ch);
  val *= sgn;
}
int main() {
  get(n), get(m);
  for (int i = 1; i <= n; ++i) get(v[i]);
  for (int st, dr, i = 1; i <= m; ++i) {
    get(st), get(dr);
    qs[dr].emplace_back(st, i);
  }
  for (int i = 2; i < V; ++i)
    if (!lst[i])
      for (int j = i; j < V; j += i) lst[j] = i;
  for (int i = 1; i <= n; ++i) {
    getp(v[i], p[i]);
    int t, pop, siz = p[i].size();
    for (int msk = 0; msk < (1 << siz); ++msk) {
      t = 1;
      pop = 0;
      for (int lg = 0; lg < siz; ++lg)
        if (msk & (1 << lg)) {
          t *= p[i][lg];
          pop += 1;
        }
      for (int c = 0; c <= 7; ++c) {
        if (mp[t][c]) lft[siz - pop + c] = max(lft[siz - pop + c], mp[t][c]);
      }
      mp[t][siz - pop] = i;
    }
    for (auto q : qs[i]) {
      for (int c = 0; c <= 14; ++c)
        if (q.first <= lft[c]) {
          ant[q.second] = c;
          break;
        }
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ant[i]);
  return 0;
}
