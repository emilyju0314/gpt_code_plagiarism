#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("-ffloat-store")
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403() {}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
template <class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T> &V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= ((long long int)(V).size());
         pw *= 2, ++k) {
      jmp.emplace_back(((long long int)(V).size()) - pw * 2 + 1);
      for (int j = 0; j < (((long long int)(jmp[k]).size())); ++j)
        jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    b++;
    assert(a < b);
    int dep = 31 - __builtin_clz(b - a);
    return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};
const long long int N = 2048;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<vector<bool>> a;
vector<vector<long long int>> b(1);
vector<RMQ<long long int>> bf(N, RMQ<long long int>(b[0]));
long long int queryx(long long int id, long long int l, long long int r,
                     long long int L, long long int R, long long int ly,
                     long long int ry) {
  if (r < L || R < l) return 0;
  if (L <= l && r <= R) return bf[id].query(ly, ry);
  long long int m = (l + r) / 2;
  return max(queryx(2 * id, l, m, L, R, ly, ry),
             queryx(2 * id + 1, m + 1, r, L, R, ly, ry));
}
long long int query(long long int lx, long long int rx, long long int ly,
                    long long int ry) {
  ;
  return queryx(1, 0, n - 1, lx, rx, ly, ry);
}
void buildx(long long int id, long long int l, long long int r) {
  if (l == r) {
    bf[id] = RMQ<long long int>(b[l]);
    return;
  }
  long long int mid = (l + r) / 2;
  buildx(2 * id, l, mid);
  buildx(2 * id + 1, mid + 1, r);
  vector<long long int> b;
  for (long long int i = 0; i < m; i++)
    b.push_back(max(bf[2 * id].query(i, i), bf[2 * id + 1].query(i, i)));
  bf[id] = RMQ<long long int>(b);
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> m;
    a.resize(n, vector<bool>(m));
    b.clear();
    b.resize(n, vector<long long int>(m, 0));
    for (i = 0; i < (n); ++i) {
      for (j = 0; j < (m); ++j) {
        cin >> in;
        a[i][j] = (in == 1);
      }
    }
    for (i = (n - 1); i >= (0); --i)
      for (j = (m - 1); j >= (0); --j) {
        if (a[i][j]) b[i][j] = 1;
        if (i == n - 1 || j == m - 1) continue;
        if (!a[i][j] || !a[i + 1][j]) continue;
        if (!a[i][j + 1]) continue;
        if (!a[i + 1][j] || !a[i + 1][j + 1]) continue;
        if (!a[i][j + 1] || !a[i + 1][j + 1]) continue;
        b[i][j] = 1 + min({b[i + 1][j + 1], b[i + 1][j], b[i][j + 1]});
      };
    ;
    buildx(1, 0, n - 1);
    long long int q;
    cin >> q;
    while (q--) {
      long long int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--;
      y1--;
      x2--;
      y2--;
      ;
      long long int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
      while (r - l > 1) {
        const long long int len = (l + r) / 2;
        if (query(x1, x2 - len + 1, y1, y2 - len + 1) >= len)
          l = len;
        else
          r = len;
      }
      cout << l << "\n";
    }
  }
  aryanc403();
  return 0;
}
