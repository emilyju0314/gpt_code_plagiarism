#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sa[50000][2], a = 0;
int main() {
  scanf("%d", &k);
  if (k % 2 == 0) {
    puts("NO");
    return 0;
  }
  if (k == 1) {
    puts("YES");
    puts("2 1");
    puts("1 2");
    return 0;
  }
  puts("YES");
  int cou = 0;
  int vis[220] = {0};
  for (int i = 1; i <= k + 2; i++) {
    if (i == 1) {
      for (int j = 2; j <= k; j++) {
        sa[cou][0] = 1;
        sa[cou++][1] = j;
        vis[j]++;
      }
      continue;
    }
    for (int j = k + 2, l = 0; j > i && l < k - vis[i]; j--, l++) {
      sa[cou][0] = i;
      sa[cou++][1] = j;
      vis[j]++;
    }
  }
  printf("%d %d\n", k * 2 + 4, cou * 2 + 1);
  printf("%d %d\n", 1, k + 3);
  for (int i = 0; i < cou; i++) {
    printf("%d %d\n", sa[i][0], sa[i][1]);
    printf("%d %d\n", sa[i][0] + k + 2, sa[i][1] + k + 2);
  }
  return 0;
}
