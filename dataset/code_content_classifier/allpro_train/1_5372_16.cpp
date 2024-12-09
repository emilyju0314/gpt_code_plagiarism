#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v;
  int a[n + 1], x[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    x[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 1; j <= i; j++) {
      for (int k = j; k <= n; k += i) {
        if (x[k] != x[j]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
    }
    if (flag == 0) {
      v.push_back(i);
    }
  }
  printf("%d\n", (int)v.size());
  for (int i = 0; i < v.size(); i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}
