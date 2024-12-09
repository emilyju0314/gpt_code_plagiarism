#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> v(n);
    for (int& x : v) scanf("%d", &x);
    int mm = 1;
    vector<int> res(n, 1e9);
    for (int i = 0; i < n; i++) {
      mm = min(mm, v[i] - i);
      res[i] = mm + i;
    }
    mm = n;
    for (int i = n - 1; i >= 0; i--) {
      mm = min(mm, v[i] + i);
      res[i] = min(res[i], mm - i);
    }
    printf("%d\n", *max_element(res.begin(), res.end()));
  }
  return 0;
}
