#include <bits/stdc++.h>
using namespace std;
int n, k, A[105], B[105], cnt, pos;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    if (A[i] == 0) {
      ++cnt;
      pos = i;
    }
  }
  A[n + 1] = 1e9;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &B[i]);
  }
  if (cnt >= 2) {
    puts("YES");
    return 0;
  }
  if (cnt == 0) {
    for (int i = 1; i <= n; i++) {
      if (A[i - 1] > A[i]) {
        puts("YES");
        return 0;
      }
    }
    puts("NO");
    return 0;
  }
  if (cnt == 1) {
    if (A[pos - 1] < B[1] && B[1] < A[pos + 1]) {
      A[pos] = B[1];
      for (int i = 1; i <= n; i++) {
        if (A[i - 1] > A[i]) {
          puts("YES");
          return 0;
        }
      }
      puts("NO");
    } else
      puts("YES");
  }
}
