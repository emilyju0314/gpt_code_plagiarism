#include <bits/stdc++.h>
using namespace std;
const int N_ = 5050;
int N, T[N_];
int C[N_];
int ans[N_];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &T[i]);
  }
  for (int i = 1; i <= N; i++) {
    fill(C, C + N + 1, 0);
    int best_c = 0, best_t = -1;
    for (int j = i; j <= N; j++) {
      int c = ++C[T[j]];
      if (c > best_c || (c == best_c && T[j] < best_t))
        best_c = c, best_t = T[j];
      ++ans[best_t];
    }
  }
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
  return 0;
}
