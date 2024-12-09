#include <bits/stdc++.h>
using namespace std;
int x, a[2100], cnt, n, k, mp[2010], d[2010], lst1, lst2, origin;
queue<int> q;
void bfs() {
  lst1 = cnt;
  for (int i = lst2 + 1; i <= lst1; i++) {
    int tmp = a[i];
    for (int j = 1; j <= origin; j++)
      if (!d[a[j] + tmp + n] && (a[j] + tmp + n) > 0 &&
          (a[j] + tmp + n) <= 2000) {
        a[++cnt] = a[j] + tmp;
        d[a[j] + tmp + n] = d[tmp + n] + 1;
        if (!(a[j] + tmp)) return;
      }
  }
  lst2 = lst1;
  bfs();
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    if (!mp[x]) a[++cnt] = x - n;
    mp[x]++;
  }
  sort(a + 1, a + cnt + 1);
  if (mp[n]) {
    printf("1");
    return 0;
  }
  if (a[cnt] < 0 || a[1] > 0)
    printf("-1");
  else {
    for (int i = 1; i <= cnt; i++) {
      d[a[i] + n] = 1;
      q.push(a[i]);
    }
    origin = cnt;
    bfs();
    printf("%d", d[n]);
  }
}
