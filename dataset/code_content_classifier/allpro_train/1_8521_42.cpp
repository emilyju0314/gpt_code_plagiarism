#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
int n, k, s[MAXN], e[MAXN], a[MAXN], id[MAXN];
bool cmp(int first, int second) { return e[first] < e[second]; }
long long calc(int t) {
  if (t > n) return (long long)1e+18;
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  long long Tohka = 0;
  int cnt = 0;
  for (int i = 1; i <= t; ++i) {
    Tohka += e[id[i]];
    if (s[id[i]] > t) ++cnt;
  }
  for (int i = t + 1; i <= n; ++i)
    if (s[id[i]] >= t - 1) ++cnt;
  if (cnt <= k - 1) return Tohka;
  cnt = cnt - (k - 1);
  int tot = 0;
  for (int i = t + 1; i <= n; ++i)
    if (s[id[i]] >= t - 1 && s[id[i]] <= t) a[++tot] = id[i];
  sort(a + 1, a + tot + 1, cmp);
  if (tot < cnt) return (long long)1e+18;
  for (int i = 1, l = t; cnt; ++i) {
    for (; s[id[l]] >= t - 1 && s[id[l]] <= t && l >= 1; --l)
      ;
    if (l < 1) break;
    Tohka += e[a[i]] - e[id[l--]];
    --cnt;
  }
  if (cnt) return (long long)1e+18;
  return Tohka;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &s[i], &e[i]);
  memcpy(a, s, sizeof(a));
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  int t = a[k];
  long long Tohka = min(calc(t), min(calc(t + 1), calc(t + 2)));
  if (Tohka == (long long)1e+18)
    puts("-1");
  else
    cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
