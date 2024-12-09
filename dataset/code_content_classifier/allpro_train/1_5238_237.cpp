#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], b[maxn], c[maxn];
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < (m); ++i) scanf("%d %d %d", a + i, b + i, c + i);
  long long res = 0;
  for (int i = 0; i < (k); ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < (m); ++j)
      if (a[j] <= x && x <= b[j]) {
        int t = c[j] + x - a[j];
        res += t;
      }
  }
  cout << res << endl;
  return 0;
}
