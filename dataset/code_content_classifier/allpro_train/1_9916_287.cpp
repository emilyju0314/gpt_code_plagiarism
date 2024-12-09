#include <bits/stdc++.h>
using namespace std;
int main() {
  int num[10011], cnt = 1, sum = 1, floor = 1, n;
  for (int i = 1; i < 10011; i++) {
    if (i > sum) {
      cnt++;
      floor += cnt;
      sum += floor;
    }
    num[i] = cnt;
  }
  while (~scanf("%d", &n)) {
    if (num[n] != num[n + 1])
      printf("%d\n", num[n]);
    else
      printf("%d\n", num[n] - 1);
  }
  return 0;
}
