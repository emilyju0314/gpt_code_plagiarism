#include <bits/stdc++.h>
int N;
int Size[500000 + 7];
int Check(int limit) {
  for (int i = 1; i <= limit; i++)
    if (Size[i] * 2 > Size[N - limit + i]) return 0;
  return 1;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", Size + i);
  std::sort(Size + 1, Size + N + 1);
  int L = 0, R = N / 2, Mid;
  for (; L < R;) {
    Mid = L + R + 1 >> 1;
    if (Check(Mid))
      L = Mid;
    else
      R = Mid - 1;
  }
  printf("%d\n", N - L);
  return 0;
}
