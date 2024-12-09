#include <bits/stdc++.h>
using namespace std;
const int MN = 100010;
long double abs(pair<int, int> a) {
  return sqrt(1LL * a.first * a.first + 1LL * a.second * a.second);
}
long long cross(pair<int, int> a, pair<int, int> b) {
  return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
long long dot(pair<int, int> a, pair<int, int> b) {
  return 1LL * a.first * b.first + 1LL * a.second * b.second;
}
bool check(pair<int, int> a, pair<int, int> b, int t) {
  if (t)
    return (long double)dot(a, b) * 2 + 1e-12 >= abs(a) * abs(b);
  else
    return dot(a, b) >= 0;
}
int N;
struct Info {
  pair<int, int> p;
  int flip;
  int id;
  bool operator<(const Info &i) const {
    if (cross(p, i.p))
      return cross(p, i.p) < 0;
    else
      return id > i.id;
  }
};
priority_queue<Info> pq;
int fa[MN], rnk[MN], Xor[MN];
void init() {
  for (int i = 0; i < N; i++) {
    fa[i] = i;
    rnk[i] = 0;
  }
}
int find(int u) {
  if (fa[u] == u)
    return u;
  else
    return find(fa[u]);
}
int color(int u) {
  if (fa[u] == u)
    return 0;
  else
    return color(fa[u]) ^ Xor[u];
}
void mrg(int u, int v, int t) {
  if (rnk[u] < rnk[v]) swap(u, v);
  fa[v] = u;
  if (t) Xor[v] = 1;
  if (rnk[u] == rnk[v]) rnk[u]++;
}
int main() {
  cout << fixed;
  cout.precision(20);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int flip = 0;
    if (y < 0) {
      x = -x;
      y = -y;
      flip = 1;
    } else if (y == 0 && x < 0) {
      x = -x;
      flip = 1;
    }
    pq.push({{x, y}, flip, i});
  }
  if (N == 1) {
    printf("1");
    return 0;
  }
  init();
  while (pq.size() >= 2) {
    int sz = pq.size();
    Info info1 = pq.top();
    pq.pop();
    Info info2 = pq.top();
    pq.pop();
    Info info3;
    if (sz >= 3) {
      info3 = pq.top();
      pq.pop();
    } else
      info3 = info2;
    Info info;
    if (check(info1.p, info2.p, sz >= 3)) {
      if (sz >= 3) pq.push(info3);
      mrg(info1.id, info2.id, info1.flip ^ info2.flip ^ 1);
      info.id = find(info1.id);
      if (info1.id == info.id) {
        info.flip = info1.flip;
        info.p = {info1.p.first - info2.p.first,
                  info1.p.second - info2.p.second};
      } else {
        info.flip = info2.flip;
        info.p = {info2.p.first - info1.p.first,
                  info2.p.second - info1.p.second};
      }
    } else if (sz >= 3 && check(info2.p, info3.p, sz >= 3)) {
      if (sz >= 3) pq.push(info1);
      mrg(info2.id, info3.id, info2.flip ^ info3.flip ^ 1);
      info.id = find(info2.id);
      if (info2.id == info.id) {
        info.flip = info2.flip;
        info.p = {info2.p.first - info3.p.first,
                  info2.p.second - info3.p.second};
      } else {
        info.flip = info3.flip;
        info.p = {info3.p.first - info2.p.first,
                  info3.p.second - info2.p.second};
      }
    } else {
      if (sz >= 3) pq.push(info2);
      mrg(info1.id, info3.id, info1.flip ^ info3.flip);
      info.id = find(info1.id);
      if (info1.id == info.id) {
        info.flip = info1.flip;
        info.p = {info1.p.first + info3.p.first,
                  info1.p.second + info3.p.second};
      } else {
        info.flip = info3.flip;
        info.p = {info1.p.first + info3.p.first,
                  info1.p.second + info3.p.second};
      }
    }
    if (info.p.second < 0) {
      info.p.first = -info.p.first;
      info.p.second = -info.p.second;
      info.flip ^= 1;
    } else if (info.p.second == 0 && info.p.first < 0) {
      info.p.first = -info.p.first;
      info.flip ^= 1;
    }
    pq.push(info);
  }
  for (int i = 0; i < N; i++) {
    if (color(i))
      printf("1 ");
    else
      printf("-1 ");
  }
}
