#include <bits/stdc++.h>
using namespace std;
long long int m, n, ans;
long long int a, b, l, k, j, h;
typedef struct {
  long long int a, b;
} fhs;
fhs p[1100000];
bool cmp(fhs a1, fhs b1) {
  if (a1.b != b1.b) {
    return a1.b < b1.b;
  } else {
    return a1.a < b1.a;
  }
}
int main() {
  cin >> m;
  for (int x = 0; x < m; x++) {
    cin >> p[x].a;
    for (int y = 0; y < p[x].a; y++) {
      cin >> a;
      p[x].b = max(p[x].b, a);
    }
  }
  sort(p, p + m, cmp);
  for (int x = 1; x < m; x++) {
    ans += (p[x].b - p[x - 1].b) * p[x - 1].a;
    p[x].a += p[x - 1].a;
  }
  printf("%lld", ans);
}
