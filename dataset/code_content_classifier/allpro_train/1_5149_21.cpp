#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int iinf = 2147483647;
const long long llinf = 9223372036854775807ll;
constexpr int N = 200005;
class Point {
 public:
  int x, y, id;
} p[N];
long double qwq(Point i, Point j);
std::vector<int> G[N];
int a[N], b[N];
int sta[N], top;
int ans[N], tot;
int n;
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(p[i].x), read(p[i].y);
    p[i].id = i;
  }
  std::sort(p + 1, p + n + 1, [&](Point i, Point j) {
    if (i.x == j.x) {
      return i.y > j.y;
    }
    return i.x > j.x;
  });
  int num = 0;
  for (int i = 1, j = 1; i <= n; i = j = j + 1) {
    while (j < n && p[j + 1].x == p[i].x) {
      ++j;
    }
    ++num;
    for (int k = i; k <= j; ++k) {
      if (p[k].y == p[i].y) {
        G[num].push_back(p[k].id);
      }
    }
    p[num] = Point{p[i].x, p[i].y, num};
  }
  for (int i = 1; i <= num; ++i) {
    if (top && qwq(p[sta[top]], p[i]) >= 0) {
      continue;
    }
    while (top > 1 &&
           qwq(p[sta[top]], p[i]) < qwq(p[sta[top - 1]], p[sta[top]])) {
      --top;
    }
    sta[++top] = i;
  }
  for (int i = 1; i <= top; ++i) {
    for (int j : G[p[sta[i]].id]) {
      ans[++tot] = j;
    }
  }
  std::sort(ans + 1, ans + tot + 1);
  for (int i = 1; i <= tot; ++i) {
    write(ans[i]), putchar(' ');
  }
  putchar('\n');
  return 0;
}
long double qwq(Point i, Point j) {
  return static_cast<long double>(i.x) * j.x * (i.y - j.y) / i.y / j.y /
         (i.x - j.x);
}
template <typename T>
inline void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template <typename T>
inline void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    write(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      write(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}
