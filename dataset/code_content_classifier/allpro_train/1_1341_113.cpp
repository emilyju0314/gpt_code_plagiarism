#include <bits/stdc++.h>
using namespace std;
string a[300007], b[300007], c[300007], d[300007];
int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d", &a, &b, &c);
  scanf("%d%d%d", &d, &e, &f);
  if (a - d && b - e && c - f)
    puts("NO");
  else
    puts("YES");
  return 0;
}
