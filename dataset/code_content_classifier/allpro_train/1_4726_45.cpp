#include <bits/stdc++.h>
using namespace std;
int s[10004][104] = {0};
int a[105];
int n, i, j, cnt, ppp;
bool cmp(int a, int b) { return a > b; }
void dfs() {
  int Max = 0, cnt = 0, k = 0, pos;
  int tmp[105];
  for (i = 0; i < n; i++) Max = max(a[i], Max);
  for (i = 0; i < n; i++)
    if (a[i] == Max) {
      cnt++;
      tmp[k++] = i;
    }
  if (cnt == n) return;
  if (cnt == 1) {
    Max = 0;
    for (i = 0; i < n; i++)
      if (i != tmp[0] && a[i] > Max) {
        Max = a[i];
        pos = i;
      }
    s[ppp][tmp[0]] = s[ppp][pos] = 1;
    ppp++;
    if (a[tmp[0]]) a[tmp[0]]--;
    if (a[pos]) a[pos]--;
  } else if (cnt & 1) {
    s[ppp][tmp[0]] = s[ppp][tmp[1]] = s[ppp][tmp[2]] = 1;
    ppp++;
    for (i = 3; i < cnt; i += 2, ppp++) {
      s[ppp][tmp[i]] = s[ppp][tmp[i + 1]] = 1;
    }
    for (i = 0; i < cnt; i++)
      if (a[tmp[i]]) a[tmp[i]]--;
  } else {
    for (i = 0; i < cnt; i += 2, ppp++) {
      s[ppp][tmp[i]] = s[ppp][tmp[i + 1]] = 1;
    }
    for (i = 0; i < cnt; i++)
      if (a[tmp[i]]) a[tmp[i]]--;
  }
  dfs();
}
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  ppp = 0;
  dfs();
  printf("%d\n", a[0]);
  printf("%d\n", ppp);
  for (i = 0; i < ppp; i++) {
    for (j = 0; j < n; j++) printf("%d", s[i][j]);
    printf("\n");
  }
  return 0;
}
