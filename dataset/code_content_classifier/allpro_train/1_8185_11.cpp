#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool cmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool cmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int n, ed, a[1001234], b[1001234];
long long pA[1001234], pB[1001234];
pair<int, int> dif[1001234];
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i), pA[i] = pA[i - 1] + a[i];
  for (i = 1; i <= n; i++) scanf("%d", b + i), pB[i] = pB[i - 1] + b[i];
  if (pA[n] < pB[n])
    for (i = ed = 1; i <= n; i++) swap(pA[i], pB[i]);
  for (i = 0, j = 0; i <= n; i++) {
    while (j + 1 <= n && pB[j + 1] <= pA[i]) ++j;
    if (dif[pA[i] - pB[j]] != make_pair(0, 0)) {
      pair<int, int> o = dif[pA[i] - pB[j]];
      if (ed) {
        printf("%d\n", j - o.second + 1);
        for (k = o.second; k <= j; k++) printf("%d ", k);
        printf("\n%d\n", i - o.first + 1);
        for (k = o.first; k <= i; k++) printf("%d ", k);
      } else {
        printf("%d\n", i - o.first + 1);
        for (k = o.first; k <= i; k++) printf("%d ", k);
        printf("\n%d\n", j - o.second + 1);
        for (k = o.second; k <= j; k++) printf("%d ", k);
      }
      return 0;
    }
    dif[pA[i] - pB[j]] = make_pair(i + 1, j + 1);
  }
  cout << ed;
  return 0;
}
