#include <bits/stdc++.h>
using namespace std;
long long bes, res;
void update(long long wait, long long tmp) {
  if (bes == -1 || bes > wait) bes = wait, res = tmp;
}
int main() {
  long long ts, tf, t;
  scanf("%I64d %I64d %I64d", &ts, &tf, &t);
  int n;
  scanf("%d", &n);
  bes = -1;
  res = -1;
  long long now = ts;
  for (int i = 1; i <= n; ++i) {
    long long tmp;
    scanf("%I64d", &tmp);
    if (now >= tmp) {
      if (now + t > tf) break;
      long long wait = now - (tmp - 1);
      update(wait, tmp - 1);
      now += t;
    } else {
      update(0, now);
      break;
    }
  }
  if (now + t <= tf) update(0, now);
  printf("%I64d\n", res);
  return 0;
}
