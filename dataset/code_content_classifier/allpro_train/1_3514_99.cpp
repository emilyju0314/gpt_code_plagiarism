#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a[200005];
vector<int> b[2];
bool used[200005];
map<int, int> d;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  int res = 0;
  for (i = 0; i < n; i++) d[a[i]]++;
  int even = 0;
  int odd = 0;
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0)
      even++;
    else
      odd++;
    b[a[i] % 2].push_back(i);
  }
  if (even > odd) {
    int p = 1;
    for (i = 0; i < b[0].size(); i++) {
      if (even == odd) break;
      int ind = b[0][i];
      if (d[a[ind]] == 1) continue;
      while (d[p]) p += 2;
      d[a[ind]]--;
      a[ind] = p;
      d[a[ind]]++;
      even--;
      odd++;
      res++;
      used[ind] = 1;
      if (p > m) return 0 * printf("-1\n");
    }
    for (i = 0; i < b[0].size(); i++) {
      if (even == odd) break;
      int ind = b[0][i];
      if (used[ind]) continue;
      while (d[p]) p += 2;
      d[a[ind]]--;
      a[ind] = p;
      d[a[ind]]++;
      even--;
      odd++;
      res++;
      if (p > m) return 0 * printf("-1\n");
    }
  } else {
    int p = 2;
    for (i = 0; i < b[1].size(); i++) {
      if (even == odd) break;
      int ind = b[1][i];
      if (d[a[ind]] == 1) continue;
      while (d[p]) p += 2;
      d[a[ind]]--;
      a[ind] = p;
      d[a[ind]]++;
      even++;
      odd--;
      res++;
      used[ind] = 1;
      if (p > m) return 0 * printf("-1\n");
    }
    for (i = 0; i < b[1].size(); i++) {
      if (even == odd) break;
      int ind = b[1][i];
      if (used[ind]) continue;
      while (d[p]) p += 2;
      d[a[ind]]--;
      a[ind] = p;
      d[a[ind]]++;
      even++;
      odd--;
      res++;
      if (p > m) return 0 * printf("-1\n");
    }
  }
  int p = 2;
  for (i = 0; i < b[0].size(); i++) {
    int ind = b[0][i];
    if (d[a[ind]] == 1) continue;
    while (d[p]) p += 2;
    d[a[ind]]--;
    a[ind] = p;
    d[a[ind]]++;
    res++;
    if (p > m) return 0 * printf("-1\n");
  }
  p = 1;
  for (i = 0; i < b[1].size(); i++) {
    int ind = b[1][i];
    if (d[a[ind]] == 1) continue;
    while (d[p]) p += 2;
    d[a[ind]]--;
    a[ind] = p;
    d[a[ind]]++;
    res++;
    if (p > m) return 0 * printf("-1\n");
  }
  printf("%d\n", res);
  for (i = 0; i < n; i++) {
    if (i == 0)
      printf("%d", a[i]);
    else
      printf(" %d", a[i]);
  }
  printf("\n");
}
