#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool flag = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') flag = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return flag ? x : -x;
}
const int N = 1e3 + 10;
int f[N * N][2];
int n, a[N];
int tot;
bool endd[N * N];
int id[N], ans[N][N];
bool flg = 0;
bool bo;
inline void work(int k, int tt, int step, int p) {
  if (bo) return;
  if (step > k) {
    endd[p] = 1;
    bo = 1;
    return;
  }
  if (endd[f[p][0]] == 0) {
    if (f[p][0] == 0) f[p][0] = ++tot;
    ans[tt][step] = 0;
    work(k, tt, step + 1, f[p][0]);
  }
  if (bo) return;
  if (endd[f[p][1]] == 0) {
    if (f[p][1] == 0) f[p][1] = ++tot;
    ans[tt][step] = 1;
    work(k, tt, step + 1, f[p][1]);
  }
}
inline bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  n = read();
  tot = 1;
  for (register int i = 1; i <= n; i++) a[i] = read(), id[i] = i;
  sort(id + 1, id + 1 + n, cmp);
  for (register int i = 1; i <= n; i++) {
    bo = 0;
    work(a[id[i]], id[i], 1, 1);
    if (bo == 0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= a[i]; j++) printf("%d", ans[i][j]);
    cout << endl;
  }
  return 0;
}
