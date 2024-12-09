#include <bits/stdc++.h>
using namespace std;
const int N = 7e4 + 50, M = 10;
char s[N][M];
int pn, ans[N], res[N];
struct P {
  int x, y;
} p[N * M];
int lcp(P a, P b) {
  int cnt = 0;
  while (a.y != 9 && b.y != 9) {
    if (s[a.x][a.y] != s[b.x][b.y]) return cnt;
    ++cnt, ++a.y, ++b.y;
  }
  return cnt;
}
bool operator<(P a, P b) {
  int l = lcp(a, b);
  a.y += l, b.y += l;
  if (a.y != 9 && b.y != 9)
    return s[a.x][a.y] < s[b.x][b.y];
  else
    return a.y == 9 && b.y != 9;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (n); ++i) {
    scanf("%s", s[i]);
    ans[i] = 9;
    res[i] = 0;
  }
  if (n == 1) {
    printf("%c\n", s[1][0]);
    return 0;
  }
  for (int i = 1; i <= (n); ++i)
    for (int j = 0; j < (9); ++j) {
      p[++pn] = (P){i, j};
    }
  sort(p + 1, p + pn + 1);
  for (int i = 1; i <= (pn); ++i) {
    int tmp = 0;
    int j = i - 1;
    while (j >= 1 && p[j].x == p[i].x) --j;
    if (j) {
      int l = lcp(p[j], p[i]);
      (tmp < l + 1 ? tmp = l + 1 : tmp);
    }
    j = i + 1;
    while (j <= pn && p[j].x == p[i].x) ++j;
    if (j <= pn) {
      int l = lcp(p[j], p[i]);
      (tmp < l + 1 ? tmp = l + 1 : tmp);
    }
    if (tmp <= 9 - p[i].y) {
      if (tmp < ans[p[i].x]) {
        ans[p[i].x] = tmp;
        res[p[i].x] = p[i].y;
      }
    }
  }
  for (int i = 1; i <= (n); ++i) {
    for (int j = 0; j < (ans[i]); ++j) putchar(s[i][res[i] + j]);
    puts("");
  }
  return 0;
}
