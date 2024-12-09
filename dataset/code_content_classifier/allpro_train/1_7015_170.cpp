#include <bits/stdc++.h>
int main() {
  long spd[110], ram[110], hdd[110], i, j, cost[110], best, besti, n;
  bool f[110];
  while (scanf("%ld", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%ld%ld%ld%ld", &spd[i], &ram[i], &hdd[i], &cost[i]);
      f[i] = false;
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (spd[i] > spd[j] && ram[i] > ram[j] && hdd[i] > hdd[j]) f[j] = true;
      }
    }
    best = 10000;
    for (i = 0; i < n; i++) {
      if (f[i] == false && cost[i] < best) {
        best = cost[i];
        besti = i;
      }
    }
    printf("%ld\n", besti + 1);
  }
  return 0;
}
