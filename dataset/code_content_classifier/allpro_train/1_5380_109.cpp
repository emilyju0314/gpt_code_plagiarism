#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  int ans = n;
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < n; j++) {
      if (abs(A[i] - A[j]) % 2 == 1) x++;
    }
    ans = min(ans, x);
  }
  cout << ans;
}
