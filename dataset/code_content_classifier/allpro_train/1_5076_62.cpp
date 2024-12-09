#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, ans, p00, p0to[maxn], pto0[maxn], cnt[maxn], p[maxn], b[maxn],
    ansp[maxn];
int main() {
  scanf("%d", &n);
  puts("? 0 0");
  fflush(stdout);
  scanf("%d", &p00);
  for (int i = 1; i < n; i++) {
    printf("? 0 %d\n", i);
    fflush(stdout);
    scanf("%d", &p0to[i]);
    printf("? %d 0\n", i);
    fflush(stdout);
    scanf("%d", &pto0[i]);
  }
  puts("!");
  for (int i = 0; i < n; i++) {
    bool boo = true;
    b[0] = i;
    p[0] = p00 ^ i;
    if (p[0] >= n) continue;
    for (int j = 0; j < n; j++) cnt[j] = 0;
    cnt[p[0]]++;
    for (int j = 1; j < n; j++) {
      p[j] = pto0[j] ^ b[0];
      if (p[j] >= n || cnt[p[j]] == 1) {
        boo = false;
        break;
      }
      cnt[p[j]]++;
    }
    if (!boo) continue;
    for (int j = 0; j < n; j++) cnt[j] = 0;
    cnt[b[0]]++;
    for (int j = 1; j < n; j++) {
      b[j] = p0to[j] ^ p[0];
      if (b[j] >= n || cnt[b[j]] == 1) {
        boo = false;
        break;
      }
      cnt[b[j]]++;
    }
    if (!boo) continue;
    for (int i = 0; i < n; i++)
      if (p[b[i]] != i) {
        boo = false;
        break;
      }
    if (!boo) continue;
    if (boo) ans++;
    if (ans == 1)
      for (int i = 0; i < n; i++) ansp[i] = p[i];
  }
  printf("%d\n%d", ans, ansp[0]);
  for (int i = 1; i < n; i++) printf(" %d", ansp[i]);
  return 0;
}
