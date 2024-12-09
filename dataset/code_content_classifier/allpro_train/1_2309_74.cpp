#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int num[SIZE], lt[SIZE], d[SIZE], l[SIZE];
void copy(int n) {
  memcpy(d, num, sizeof(int) * n);
  memcpy(l, lt, sizeof(int) * n);
}
bool cmp(int x, int y) {
  if (d[x] != d[y]) return d[x] > d[y];
  return l[x] < l[y];
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int m, a;
  scanf("%d%d", &m, &a);
  if (n == 1) return 0 * puts("1");
  for (int i = 0; i < (a); ++i) {
    int(x);
    scanf("%d", &x);
    x--;
    num[x]++;
    lt[x] = i;
  }
  vector<int> id;
  for (int i = 0; i < (n); ++i) id.push_back(i);
  for (int i = 0; i < (n); ++i) {
    copy(n);
    for (int j2 = (a); j2 < (m); ++j2) {
      int nxt = -1;
      pair<int, int> ma = make_pair(-1, -1);
      for (int j = 0; j < (n); ++j) {
        if (d[j] < d[i] || (d[j] == d[i] && l[j] > l[i])) {
          if (ma < make_pair(d[j], l[j])) {
            ma = make_pair(d[j], l[j]);
            nxt = j;
          }
        }
      }
      if (ma.first != -1) {
        d[nxt]++;
        l[nxt] = j2;
      }
    }
    sort((id).begin(), (id).end(), cmp);
    bool suc = 0;
    for (int j = 0; j < (k); ++j) {
      if (id[j] == i && d[i]) suc = 1;
    }
    if (suc) {
      printf("%d ", 1);
      continue;
    }
    copy(n);
    for (int j = (a); j < (m); ++j) {
      d[i]++;
      l[i] = j;
    }
    sort((id).begin(), (id).end(), cmp);
    for (int j = 0; j < (k); ++j) {
      if (id[j] == i && d[i]) suc = 1;
    }
    if (suc) {
      printf("2 ");
    } else
      printf("3 ");
  }
  return 0;
}
