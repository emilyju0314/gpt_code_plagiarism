#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, x1, y3, x2, y2;
long long h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
long long dist[N];
bool st[N];
struct Move {
  long long x, y, p;
} im[N];
bool cmpx(const Move &a, const Move &b) { return a.x < b.x; }
bool cmpy(const Move &a, const Move &b) { return a.y < b.y; }
void add(long long a, long long b, long long f) {
  e[idx] = b, ne[idx] = h[a], w[idx] = f, h[a] = idx++;
}
void init() {
  memset(h, -1, sizeof h);
  idx = 0;
}
void dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(st, 0, sizeof st);
  dist[0] = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      heap;
  heap.push({dist[0], 0});
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();
    long long ver = t.second;
    if (ver == m + 1) break;
    if (st[ver]) continue;
    st[ver] = true;
    for (long long j = h[ver]; j != -1; j = ne[j]) {
      long long k = e[j];
      if (dist[k] > dist[ver] + w[j])
        dist[k] = dist[ver] + w[j], heap.push({dist[k], k});
    }
  }
}
int main() {
  init();
  scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &x1, &y3, &x2, &y2);
  im[0].x = x1, im[0].y = y3, im[0].p = 0;
  im[m + 1].x = x2, im[m + 1].y = y2, im[m + 1].p = m + 1;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld", &im[i].x, &im[i].y);
    im[i].p = i;
  }
  for (long long i = 0; i <= m; i++)
    add(im[i].p, im[m + 1].p,
        abs(im[i].x - im[m + 1].x) + abs(im[i].y - im[m + 1].y)),
        add(im[m + 1].p, im[i].p,
            abs(im[m + 1].x - im[i].x) + abs(im[m + 1].y - im[i].y));
  sort(im, im + m + 1, cmpx);
  for (long long i = 0; i <= m - 1; i++)
    add(im[i].p, im[i + 1].p, abs(im[i].x - im[i + 1].x)),
        add(im[i + 1].p, im[i].p, abs(im[i].x - im[i + 1].x));
  sort(im, im + m + 1, cmpy);
  for (long long i = 0; i <= m - 1; i++)
    add(im[i].p, im[i + 1].p, abs(im[i].y - im[i + 1].y)),
        add(im[i + 1].p, im[i].p, abs(im[i].y - im[i + 1].y));
  dijkstra();
  printf("%lld\n", dist[m + 1]);
  return 0;
}
