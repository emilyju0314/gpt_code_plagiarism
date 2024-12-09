#include <bits/stdc++.h>
using namespace std;
long long int n, s[1100], d[1100];
long long int day, cur, mult;
int main() {
  day = 0;
  scanf("%lld", &n);
  for (int x = 1; x <= n; x += 1) {
    scanf("%lld %lld", &s[x], &d[x]);
    if (x == 1) {
      day = s[x];
    } else {
      cur = s[x];
      mult = 1;
      while (cur < day) {
        cur += mult * d[x];
      }
      if (day == cur) {
        day++;
        while (cur < day) {
          cur += mult * d[x];
        }
      }
      day = cur;
    }
  }
  printf("%lld\n", day);
  return 0;
}
