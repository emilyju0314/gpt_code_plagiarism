#include <bits/stdc++.h>
using namespace std;
long long int A[10][10];
int main() {
  int(n);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%I64d", &A[i][j]);
  ;
  for (int k = 0; k < n; ++k)
    for (int j = 0; j < n; ++j)
      for (int i = 0; i < n; ++i) A[i][j] = min(A[i][k] + A[k][j], A[i][j]);
  long long int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) ans = max(ans, A[i][j]);
  cout << ans;
}
