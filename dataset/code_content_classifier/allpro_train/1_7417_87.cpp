#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int a[MAXN], N;
int best[2][MAXN], B[2];
int main() {
  scanf("%d", &N);
  for (int i = (0); i < (N); i++) scanf("%d", a + i);
  for (int i = (0); i < (N); i++) a[i] -= i;
  B[0] = B[1] = 0;
  for (int i = (0); i < (N); i++) {
    int lo = 0, hi = B[1];
    while (lo != hi) {
      int m = lo + (hi - lo) / 2;
      if (best[1][m] <= a[i])
        lo = m + 1;
      else
        hi = m;
    }
    B[1] = max(B[1], lo + 1);
    best[1][lo] = a[i];
    lo = 0, hi = B[0];
    while (lo != hi) {
      int m = lo + (hi - lo) / 2;
      if (best[0][m] - 1 <= a[i])
        lo = m + 1;
      else
        hi = m;
    }
    if (lo != 0 && best[0][lo - 1] - 1 == a[i] && a[i - 1] != best[0][lo - 1]) {
      B[1] = max(B[1], lo + 1);
      best[1][lo] = a[i];
      while (lo > 0 && best[1][lo - 1] == best[1][lo] + 1) best[1][--lo]--;
    }
    lo = 0, hi = B[0];
    while (lo != hi) {
      int m = lo + (hi - lo) / 2;
      if (best[0][m] <= a[i])
        lo = m + 1;
      else
        hi = m;
    }
    B[0] = max(B[0], lo + 1);
    best[0][lo] = a[i];
  }
  cout << max(0, N - max(B[0], B[1]) - 1) << endl;
  return 0;
}
