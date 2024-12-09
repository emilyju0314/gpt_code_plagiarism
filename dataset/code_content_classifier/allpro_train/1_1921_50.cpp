#include <bits/stdc++.h>
using namespace std;
const int up = 1 << 18;
const int INF = 1e9;
template <typename T>
inline T read() {
  register T sum = 0;
  register char cc = getchar();
  int sym = 1;
  while (cc != '-' && (cc > '9' || cc < '0')) cc = getchar();
  if (cc == '-') sym = -1, cc = getchar();
  sum = sum * 10 + cc - '0';
  cc = getchar();
  while (cc >= '0' && cc <= '9') sum = sum * 10 + cc - '0', cc = getchar();
  return sym * sum;
}
template <typename T>
inline T read(T &a) {
  a = read<T>();
  return a;
}
template <typename T, typename... Others>
inline void read(T &a, Others &...b) {
  a = read(a);
  read(b...);
}
int n, a[200010], id[200010], fa[200010], mp[200010];
long long ans;
pair<int, int> pos[200010];
vector<int> v[200010];
struct Data {
  pair<int, int> x, y;
  void operator+=(const pair<int, int> &o) {
    if (x < o) {
      if (x.second != o.second) y = x;
      x = o;
    } else if (y < o && x.second != o.second)
      y = o;
  }
  void operator+=(const Data &o) {
    *this += o.x;
    *this += o.y;
  }
} f[265000];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool Union(int x, int y) {
  if (!x || !y) return false;
  x = find(x), y = find(y);
  if (x == y) return false;
  if (x > y) swap(x, y);
  fa[y] = x;
  return true;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    fa[i] = i;
    ans -= a[i];
  }
  n += 1;
  fa[n] = n;
  a[0] = -INF;
  while (true) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (fa[i] == i) {
        id[i] = ++cnt;
        pos[cnt] = make_pair(-1, 0);
        mp[cnt] = i;
      }
      v[id[find(i)]].push_back(i);
    }
    if (cnt <= 1) break;
    for (int i = 0; i < up; i++)
      f[i] = {make_pair(-INF, 0), make_pair(-INF, 0)};
    for (int i = 1; i <= cnt; i++)
      for (auto j : v[i]) f[a[j]] += make_pair(a[j], i);
    for (int i = 0; i < 18; i++)
      for (int j = 0; j < up; j++)
        if (j & (1 << i)) f[j] += f[j ^ (1 << i)];
    for (int i = 1; i <= cnt; i++) {
      for (auto j : v[i]) {
        pair<int, int> t;
        auto o = f[(up - 1) ^ a[j]];
        if (o.x.second == i)
          t = o.y;
        else
          t = o.x;
        t.first += a[j];
        pos[i] = max(pos[i], t);
      }
      v[i].clear();
    }
    for (int i = 1; i <= n; i++)
      if (fa[i] == i && pos[id[i]].second && Union(i, mp[pos[id[i]].second]))
        ans += pos[id[i]].first;
  }
  printf("%lld\n", ans);
  return 0;
}
