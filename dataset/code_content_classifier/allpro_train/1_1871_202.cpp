#include <bits/stdc++.h>
using namespace std;
string s;
int check(int x) {
  int n = s.size();
  int tot = 1, last = -1, len = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '-' || s[i] == ' ') {
      if (i - last > x) return 2e9;
      if (len + i - last > x) {
        len = i - last;
        tot++;
      } else
        len += i - last;
      last = i;
    }
  }
  if (len + n - 1 - last > x) tot++;
  if (n - 1 - last > x) return 2e9;
  return tot;
}
int main() {
  int k;
  scanf("%d", &k);
  getchar();
  getline(cin, s);
  int l = 1, r = 1e7, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (check(mid) <= k)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
