#include <bits/stdc++.h>
using namespace std;
int cnt[500000 + 11];
char str[500000 + 11], rv[500000 + 11];
int n;
long long int T, a, b;
bool oka(long long int rem, long long int st, bool flg = false) {
  long long int need = (n - st) * (a + 1) + 1;
  need += (long long int)b * cnt[st];
  return need <= rem;
}
long long int calc(long long int rem, int idx) {
  if (rem <= 0) return 0;
  int lo = 0, mid;
  int hi = n - idx;
  while (lo != hi) {
    mid = lo + (hi - lo + 1) / 2;
    if (oka(rem, n - mid + 1))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}
int go(char *str) {
  int ret = 0, cur, i;
  long long int timeTaken = 0;
  for (i = n; i >= 1; i--) cnt[i] = cnt[i + 1] + (str[i] == 'w');
  for (i = 1; i <= n; i++) {
    if (str[i] == 'w') timeTaken += b;
    if (timeTaken >= T) return ret;
    timeTaken++;
    cur = i + calc(T - (timeTaken + (long long int)i * a), i);
    ret = max(ret, cur);
    timeTaken += a;
  }
  return ret;
}
int main() {
  int i, j, k, mx = 0;
  cin >> n >> a >> b >> T;
  scanf("%s", str + 1);
  mx = go(str);
  reverse(str + 1, str + n + 1);
  for (i = 1; i <= n; i++) {
    j = i + 1;
    if (j > n) j = 1;
    rv[j] = str[i];
  }
  mx = max(mx, go(rv));
  cout << mx << endl;
  return 0;
}
