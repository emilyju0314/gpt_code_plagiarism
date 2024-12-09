#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int A[105];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  int res = 0;
  for (int i = 0; i < n; ++i)
    if ((sum - A[i]) % 2 == 0) ++res;
  cout << res << endl;
  return 0;
}
