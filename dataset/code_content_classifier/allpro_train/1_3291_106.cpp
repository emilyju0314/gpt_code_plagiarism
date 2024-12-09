#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> x, y;
int main() {
  scanf("%d%d", &n, &m);
  int s = 0, s2 = 0;
  int p = 0;
  for (;;) {
    if (p % 2 == 0) {
      s += 8;
      s2++;
      x.push_back(8);
      y.push_back(1);
    } else {
      s++;
      s2 += 8;
      x.push_back(1);
      y.push_back(8);
    }
    if (s >= n - 1 && s2 >= n) break;
    p ^= 1;
  }
  x[0]++;
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  for (int o : x) printf("%d", o);
  printf("\n");
  for (int o : y) printf("%d", o);
  printf("\n");
  return 0;
}
