#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, tr, a;
int r[5005][2], c[5005][2];
int main() {
  cin >> n >> m >> k;
  for (int l = 0; l < k; l++) {
    scanf("%i%i%i", &t, &tr, &a);
    if (t == 1) {
      r[tr][0] = a;
      r[tr][1] = l + 1;
    } else {
      c[tr][0] = a;
      c[tr][1] = l + 1;
    }
  }
  for (int l = 1; l <= n; ++l) {
    for (int l2 = 1; l2 <= m; l2++) {
      if (r[l][1] > c[l2][1])
        printf("%i ", r[l][0]);
      else
        printf("%i ", c[l2][0]);
    }
    printf("\n");
  }
  return 0;
}
