#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 10005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int d1[N], d2[N], ans[N], n, x, y, u, v, w, num;
bool vis1[N], vis2[N];
vector<int> V1[N], V2[N];
bitset<N> a[N];
struct Btype {
  int x, y;
} E[N];
struct Stype {
  int d, id;
  long long r;
} s1[N], s2[N];
set<Stype> S;
inline long long myrand() {
  return ((long long)(rand() & 65535) << 32) + ((long long)rand() << 16) +
         rand();
}
inline bool operator<(const Stype p, const Stype q) {
  return p.d < q.d || p.d == q.d && p.r < q.r ||
         p.d == q.d && p.r == q.r && p.id < q.id;
}
inline bool operator>(const Stype p, const Stype q) {
  return p.d > q.d || p.d == q.d && p.r > q.r ||
         p.d == q.d && p.r == q.r && p.id > q.id;
}
inline void print() {
  printf("Yes\n");
  for (int i = (1); i <= (n); ++i) printf("%d ", ans[i] + n);
  printf("\n");
}
inline void D(int x) {
  vis1[x] = 1, num++;
  S.erase(s1[x]);
  for (auto y : V1[x])
    if (!vis1[y]) S.erase(s1[y]), s1[y].d++, S.insert(s1[y]);
}
inline bool _work() {
  for (int i = (1); i <= (n); ++i) ans[i] = i;
  random_shuffle(ans + 1, ans + n + 1);
  for (int i = (1); i <= (n - 1); ++i)
    if (a[ans[E[i].x]][ans[E[i].y]]) return 0;
  print();
  return 1;
}
inline bool work() {
  memset(vis1, 0, sizeof(vis1)), memset(vis2, 0, sizeof(vis2)),
      memset(ans, 0, sizeof(ans)), num = 0;
  S.clear();
  for (int i = (1); i <= (n); ++i)
    s1[i].r = myrand(), S.insert(s1[i]), s2[i].r = myrand();
  priority_queue<Stype, vector<Stype>, greater<Stype> > Q;
  Stype s = s2[1];
  for (int i = (2); i <= (n); ++i) s = ((s) < (s2[i]) ? (s) : (s2[i]));
  Q.push(s), ans[s.id] = S.begin()->id, vis2[s.id] = 1, D(S.begin()->id);
  while (!Q.empty()) {
    Stype s = Q.top();
    Q.pop();
    u = ans[x = s.id];
    for (auto y : V2[x])
      if (!vis2[y]) {
        s2[y].d--;
        auto it = S.lower_bound(Stype{s2[y].d + num, -1, -1});
        for (; it != S.end(); it++)
          if (!a[u][v = it->id]) {
            ans[y] = v;
            break;
          }
        if (!ans[y]) return 0;
        D(v), vis2[y] = 1, Q.push(s2[y]);
      }
  }
  print();
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); ++i) {
    scanf("%d%d", &x, &y), d2[x]++, d2[y]++;
    V2[x].push_back(y), V2[y].push_back(x);
    E[i] = Btype{x, y};
  }
  for (int i = (1); i <= (n - 1); ++i) {
    scanf("%d%d", &x, &y), x -= n, y -= n, d1[x]--, d1[y]--;
    V1[x].push_back(y), V1[y].push_back(x);
    a[x][y] = a[y][x] = 1;
  }
  for (int i = (1); i <= (n); ++i) d1[i] += n - 1;
  for (int i = (1); i <= (n); ++i)
    if (!d1[i] || d2[i] == n - 1) return 0 * printf("No\n");
  for (int i = (1); i <= (n); ++i)
    s1[i] = Stype{d1[i], i, myrand()}, s2[i] = Stype{d2[i], i, myrand()};
  for (; !_work() && !work();)
    ;
  return 0;
}
