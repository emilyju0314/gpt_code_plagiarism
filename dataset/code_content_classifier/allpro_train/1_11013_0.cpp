#include <bits/stdc++.h>
using namespace std;
int T, N;
long long X, M;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  int sol;
  long long a;
  while (T--) {
    cin >> N >> X;
    M = 0;
    for (int i = 0; i < N; i++) {
      cin >> a;
      if (M == X) continue;
      M = max(a, M);
      if (a == X) M = X;
    }
    long long sol = X / M;
    if (M == X)
      sol = 1;
    else {
      if (X % M) sol++;
      sol = max(sol, 2LL);
    }
    cout << sol << "\n";
  }
  return 0;
}
