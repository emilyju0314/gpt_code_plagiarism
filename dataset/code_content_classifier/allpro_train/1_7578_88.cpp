#include <bits/stdc++.h>
using namespace std;
const double PI = 4 * atan(1.0);
const int MAXN = 500010;
const long long INF = (int)1E9 + 10;
const int MOD = (int)(1001017);
const int P = 31;
int arr[200010];
bool can_jump[200010];
int main() {
  int n, m, s, d;
  scanf("%d %d %d %d", &n, &m, &s, &d);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  int last = 0, last_jump = 0;
  bool can = 1;
  for (int i = 0; i < n; i++) {
    if ((arr[i] - last - 1) >= s) {
      can_jump[i] = 1;
      last_jump = arr[i];
    } else {
      if ((arr[i] - last_jump + 2) > d || last_jump == 0) {
        can = 0;
        break;
      }
    }
    last = arr[i] + 1;
  }
  if (can == 0 || arr[n - 1] == m || d == 1)
    cout << "IMPOSSIBLE\n";
  else {
    last_jump = 0;
    int cnt_j = 0;
    bool first = 1;
    for (int i = 0; i < n; i++) {
      if (can_jump[i] == 1) {
        if (!first) {
          printf("JUMP %d\n", cnt_j);
          cnt_j = 0;
          last_jump = arr[i - 1] + 1;
        } else
          first = 0;
        printf("RUN %d\n", (arr[i] - last_jump - 1));
        last_jump = arr[i];
        cnt_j = 2;
      } else
        cnt_j = arr[i] - last_jump + 2;
    }
    if (cnt_j > 0) {
      printf("JUMP %d\n", cnt_j);
    }
    if ((m - arr[n - 1] - 1) > 0) printf("RUN %d\n", (m - arr[n - 1] - 1));
  }
  return 0;
}
