#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &f) {
  f = 0;
  _T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
const int N = 300005;
int fff, maxn, a[N], s[N], s1[N], s2[N];
long long ans;
int main() {
  cin >> fff;
  for (int iirre = 1; iirre <= fff; iirre++) {
    long long zzz;
    read(zzz);
    while (zzz > 0) {
      if (zzz % 2 == 1) a[iirre]++;
      zzz >>= 1;
    }
  }
  for (int iirre = 1; iirre <= fff; iirre++) s[iirre] = s[iirre - 1] + a[iirre];
  for (int iirre = 1; iirre <= fff; iirre++)
    s1[iirre] = s1[iirre - 1] + (s[iirre] & 1);
  s2[0] = 1;
  for (int iirre = 1; iirre <= fff; iirre++)
    s2[iirre] = s2[iirre - 1] + ((s[iirre] & 1) ^ 1);
  for (int iirre = 1; iirre <= fff; iirre++) {
    maxn = 0;
    int mid = max(1, iirre - 130);
    for (int j = iirre; j >= mid; j--) {
      if (a[j] > maxn) maxn = a[j];
      if (((maxn << 1) <= s[iirre] - s[j - 1]) &&
          (s[iirre] & 1) == (s[j - 1] & 1))
        ans++;
    }
    if (!(mid < 1) && !(mid > 1)) continue;
    int tmp = mid - 2;
    if (s[iirre] & 1)
      ans += s1[tmp];
    else
      ans += s2[tmp];
  }
  cout << ans << endl;
  return 0;
}
