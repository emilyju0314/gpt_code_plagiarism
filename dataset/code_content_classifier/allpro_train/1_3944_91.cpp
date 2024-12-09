#include <bits/stdc++.h>
int a[15], b[15], c[15];
int s1[4], s2[4];
bool change(int x, int s[]) {
  int num[11], i;
  memset(num, 0, sizeof(num));
  if (x < 1000) {
    s[0] = 0;
    num[0]++;
  }
  for (i = 3; x > 0; i--) {
    s[i] = x % 10;
    x = x / 10;
    num[s[i]]++;
    if (num[s[i]] > 1) return false;
  }
  return true;
}
bool solve(int n) {
  int i, j, num;
  int nn[11];
  for (i = 0; i < n; i++) {
    if (change(a[i], s2) == false) continue;
    num = 0;
    memset(nn, 0, sizeof(nn));
    for (j = 0; j < 4; j++) {
      nn[s1[j]]++;
      if (s1[j] == s2[j]) num++;
    }
    if (num != b[i]) return false;
    num = 0;
    for (j = 0; j < 4; j++) {
      nn[s2[j]]++;
      if (nn[s2[j]] >= 2 && s1[j] != s2[j]) num++;
    }
    if (num != c[i]) return false;
  }
  return true;
}
int main() {
  int n, i, num, ans;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    num = 0;
    ans = 0;
    for (i = 123; i < 10000; i++) {
      if (!change(i, s1)) continue;
      if (solve(n)) {
        num++;
        ans = i;
      }
      if (num > 1) break;
    }
    if (num == 0)
      printf("Incorrect data\n");
    else if (num == 1) {
      if (ans < 1000) printf("0");
      printf("%d\n", ans);
    } else
      printf("Need more data\n");
  }
  return 0;
}
