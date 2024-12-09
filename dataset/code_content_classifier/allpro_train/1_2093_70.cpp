#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1][2];
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i][0], &a[i][1]);
  }
  float ans = 0.0f;
  for (int i = 0; i < n - 1; i++) {
    ans += sqrtf((a[i][0] - a[i + 1][0]) * (a[i][0] - a[i + 1][0]) +
                 (a[i][1] - a[i + 1][1]) * (a[i][1] - a[i + 1][1]));
  }
  printf("%0.9f\n", (ans / 50.0) * k);
  return 0;
}
