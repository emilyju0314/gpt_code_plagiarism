#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
char s[MAXN << 1];
int sum[MAXN];
int st[MAXN];
int val[MAXN];
int pre[MAXN << 1];
int preans[MAXN << 1];
int pos[MAXN << 1];
int main() {
  int n;
  cin >> n;
  scanf("%s", s + 1);
  for (int i = n + 1; i <= n << 1; i++) s[i] = s[i - n];
  int zx = 0, zxi = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '(')
      sum[i]++;
    else
      sum[i]--;
    if (sum[i] < zx) zx = sum[i], zxi = i;
  }
  if (sum[n] != 0) {
    printf("%d\n%d %d\n", 0, 1, 1);
    return 0;
  }
  int cnt = 0;
  int ans = 0;
  for (int i = zxi + 1; i <= zxi + n; i++) {
    if (s[i] == '(')
      st[++cnt] = i;
    else {
      preans[i] = val[cnt];
      val[cnt] = 0;
      pos[i] = st[cnt];
      pre[i] = cnt;
      cnt--;
      val[cnt]++;
    }
    if (cnt == 0) ans++;
  }
  int tmp = ans;
  int l = 1, r = 1;
  for (int i = zxi + 1; i <= zxi + n; i++)
    if (s[i] == ')') {
      if (pre[i] == 1 && preans[i] + 1 > ans)
        ans = preans[i] + 1, l = pos[i], r = i;
      if (pre[i] == 2 && preans[i] + 1 + tmp > ans)
        ans = preans[i] + 1 + tmp, l = pos[i], r = i;
    }
  l = (l - 1) % n + 1;
  r = (r - 1) % n + 1;
  printf("%d\n%d %d\n", ans, l, r);
  return 0;
}
