#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 0 && m > 0)
    puts("Impossible");
  else
    printf("%d %d\n", n + m - min(n, m), n + m - min(1, m));
}
