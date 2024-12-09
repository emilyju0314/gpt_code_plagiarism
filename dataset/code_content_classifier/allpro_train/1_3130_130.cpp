#include <bits/stdc++.h>
using namespace std;
struct pnt {
  int x, y;
};
pnt p[100010];
int seq[100010], val[100010], ret[100];
int n, m;
int cmp1(const int &i, const int &j) {
  if (p[i].x == p[j].x) return p[i].y < p[j].y;
  return p[i].x < p[j].x;
}
int cmp2(const int &i, const int &j) {
  if (p[i].y == p[j].y) return p[i].x < p[j].x;
  return p[i].y < p[j].y;
}
int cmp3(const int &i, const int &j) {
  if (p[i].x + p[i].y == p[j].x + p[j].y)
    return p[i].x - p[i].y < p[j].x - p[j].y;
  return p[i].x + p[i].y < p[j].x + p[j].y;
}
int cmp4(const int &i, const int &j) {
  if (p[i].x - p[i].y == p[j].x - p[j].y)
    return p[i].x + p[i].y < p[j].x + p[j].y;
  return p[i].x - p[i].y < p[j].x - p[j].y;
}
void conduct() {
  int i;
  for (i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
  memset(val, 0, sizeof(val));
  for (i = 0; i < n; ++i) seq[i] = i;
  sort(seq, seq + n, cmp1);
  for (i = 0; i < n;)
    for (++i; i < n && p[seq[i - 1]].x == p[seq[i]].x; ++i) {
      val[seq[i]]++;
      val[seq[i - 1]]++;
    }
  for (i = 0; i < n; ++i) seq[i] = i;
  sort(seq, seq + n, cmp2);
  for (i = 0; i < n;)
    for (++i; i < n && p[seq[i - 1]].y == p[seq[i]].y; ++i) {
      val[seq[i]]++;
      val[seq[i - 1]]++;
    }
  for (i = 0; i < n; ++i) seq[i] = i;
  sort(seq, seq + n, cmp3);
  for (i = 0; i < n;)
    for (++i; i < n &&
              p[seq[i - 1]].x + p[seq[i - 1]].y == p[seq[i]].x + p[seq[i]].y;
         ++i) {
      val[seq[i]]++;
      val[seq[i - 1]]++;
    }
  for (i = 0; i < n; ++i) seq[i] = i;
  sort(seq, seq + n, cmp4);
  for (i = 0; i < n;)
    for (++i; i < n &&
              p[seq[i - 1]].x - p[seq[i - 1]].y == p[seq[i]].x - p[seq[i]].y;
         ++i) {
      val[seq[i]]++;
      val[seq[i - 1]]++;
    }
  memset(ret, 0, sizeof(ret));
  for (i = 0; i < n; ++i) ret[val[i]]++;
  for (i = 0; i <= 8; ++i) printf("%d ", ret[i]);
  printf("\n");
}
int main() {
  scanf("%d%d", &m, &n);
  conduct();
  return 0;
}
