#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void arquivo() {
  freopen("", "r", stdin);
  freopen("", "w", stdout);
}
const int N = 1000010;
const int M = 26;
const long long MOD = 1e9 + 7LL;
long long pd[M];
int lst[M];
int pos[M];
char s[N];
int n, k;
long long ans;
bool cmp(int a, int b) { return lst[a] < lst[b]; }
inline long long addMod(long long a, long long b, long long mod = MOD) {
  return (a + b + mod) % mod;
}
inline long long subMod(long long a, long long b, long long mod = MOD) {
  return (a - b + mod) % mod;
}
int main() {
  ans = 0;
  scanf("%d %d", &n, &k);
  scanf(" %s", s);
  int len = strlen(s);
  memset(lst, -1, sizeof lst);
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    lst[c] = i;
    ans = subMod(ans, pd[c]);
    pd[c] = addMod(pd[c] + 1, ans);
    ans = addMod(ans, pd[c]);
  }
  for (int i = 0; i < k; ++i) pos[i] = i;
  sort(pos, pos + k, cmp);
  for (int i = 0; i < n; ++i) {
    int c = pos[i % k];
    ans = subMod(ans, pd[c]);
    pd[c] = addMod(pd[c] + 1, ans);
    ans = addMod(ans, pd[c]);
  }
  printf("%lld\n", addMod(ans, 1LL));
  return 0;
}
