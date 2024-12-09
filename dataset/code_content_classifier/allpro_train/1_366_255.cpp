#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int A[100100], N;
int C[100100];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    C[i] = A[i];
  }
  int j;
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    for (j = 0; (i + (1 << j)) <= N; j++)
      ;
    j--;
    ans += C[i];
    C[i + (1 << j)] += C[i];
    printf("%I64d\n", ans);
  }
  return 0;
}
