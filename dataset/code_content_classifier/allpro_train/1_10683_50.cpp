#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n - 1) / 2) <= k)
    printf("no solution\n");
  else {
    for (int i = 0; i < (n); i++) {
      printf("%d %d\n", i + 1, (n + 5) * (i + 1));
    }
  }
  return 0;
}
