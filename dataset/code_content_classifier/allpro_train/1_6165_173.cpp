#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int ans = 0;
  if (N == 1 || M == 1) {
    cout << N * M;
    return 0;
  }
  if (N <= 2 && M <= 2) {
    cout << N * M;
    return 0;
  }
  if (N == 2 || M == 2) {
    int a = min(N, M);
    int b = max(N, M);
    int ans = (b / 4) * 4;
    if (b % 4 != 0) {
      if (b % 4 == 1)
        ans += 2;
      else
        ans += 4;
    }
    cout << ans << endl;
    return 0;
  } else {
    ans = N * M - N * M / 2;
    cout << ans << endl;
  }
  return 0;
}
