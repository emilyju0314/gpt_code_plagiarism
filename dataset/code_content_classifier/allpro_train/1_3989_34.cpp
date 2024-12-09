#include <bits/stdc++.h>
using namespace std;
int prt[1000000], rp[1000000], arr[1000000], clr[301][301], c[1000000],
    ob[301][301];
int n, m, size[1000000], CL, x, y;
bool done[301][301];
long long int ans;
struct Point {
  int x, y;
} q[1000000], temp[1000000];
vector<Point> vec[1000000];
vector<Point>::iterator iter;
inline int h(int x, int y) { return (x - 1) * m + y; }
int find(int x) {
  if (prt[x] == 0) return x;
  return prt[x] = find(prt[x]);
}
inline int calc(int a, int b, int pp) {
  if (a == pp) return 2;
  if (a == -pp) return 4;
  if (b == -pp) return 1;
  if (b == pp) return 3;
}
int comp(const void *p, const void *q) {
  int a = (*(struct Point *)p).y - y;
  int b = (*(struct Point *)p).x - x;
  int c = (*(struct Point *)q).y - y;
  int d = (*(struct Point *)q).x - x;
  int pp = max(labs(a), labs(b));
  int qq = max(labs(c), labs(d));
  if (pp != qq) return pp - qq;
  pp = calc(a, b, pp);
  qq = calc(c, d, qq);
  if (pp != qq) return pp - qq;
  if (pp == 1) return a - c;
  if (pp == 2) return b - d;
  if (pp == 3) return c - a;
  if (pp == 4) return d - b;
}
int main() {
  int i, j, color, num, head, tail;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      scanf("%d", &clr[i][j]), arr[h(i, j) - 1] = clr[i][j];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      scanf("%d", &ob[i][j]), arr[h(i, j) - 1 + n * m] = ob[i][j];
  sort(arr, arr + n * m * 2);
  int uniend = unique(arr, arr + n * m * 2) - arr;
  for (i = 0; i < uniend; i++) rp[i] = n * m + 1 + i, c[rp[i]] = i;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      color = lower_bound(arr, arr + uniend, clr[i][j]) - arr;
      prt[h(i, j)] = rp[color];
      size[rp[color]]++;
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (ob[i][j] != -1) {
        ob[i][j] = lower_bound(arr, arr + uniend, ob[i][j]) - arr;
        vec[find(h(i, j))].push_back((struct Point){i, j});
      }
    }
  scanf("%d%d", &i, &j);
  head = tail = 0;
  q[head] = (struct Point){i, j};
  while (head <= tail) {
    x = q[head].x;
    y = q[head].y;
    head++;
    num = find(h(x, y));
    if (done[x][y]) continue;
    done[x][y] = true;
    if (arr[ob[x][y]] == -1 || arr[c[num]] == 0) continue;
    if (c[num] == ob[x][y]) continue;
    for (iter = vec[num].begin(), i = 0; iter != vec[num].end(); iter++)
      temp[++i] = *iter;
    qsort(temp + 1, i, sizeof(temp[0]), comp);
    for (j = 1; j <= i; j++) q[++tail] = temp[j];
    ans += size[num];
    if (!rp[ob[x][y]]) {
      rp[c[num]] = 0;
      c[num] = ob[x][y];
      rp[ob[x][y]] = c[num];
    } else {
      rp[c[num]] = 0;
      prt[num] = rp[ob[x][y]];
    }
    size[rp[ob[x][y]]] += size[num];
  }
  cout << ans;
}
