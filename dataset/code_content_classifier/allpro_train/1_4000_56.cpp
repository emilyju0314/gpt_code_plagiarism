#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> A(3);
    for (__typeof(0) i = (0); i < (3); i++) cin >> A[i];
    long long ans = 1e9;
    vector<int> sol(3);
    for (__typeof(1) i = (1); i < (2 * A[0]); i++) {
      for (int j = i; j < 2 * A[1]; j += i) {
        for (__typeof(0) k = (0); k < (2); k++) {
          long long aux = abs(A[0] - i) + abs(A[1] - j);
          long long c = j * (A[2] / j) + k * j;
          aux += abs(A[2] - c);
          if (ans > aux) {
            sol[0] = i;
            sol[1] = j;
            sol[2] = c;
            ans = aux;
          }
        }
      }
    }
    cout << ans << '\n';
    for (__typeof(0) i = (0); i < (3); i++) cout << sol[i] << " ";
    cout << '\n';
  }
  return 0;
}
