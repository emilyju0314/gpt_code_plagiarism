#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long a, b, N;
  cin >> N;
  for (int p = 0; p < N; p++) {
    long long res = 0;
    cin >> a >> b;
    while (1) {
      if (a == 0 || b == 0) break;
      if (a < b) swap(a, b);
      res += (a - (a % b)) / b;
      a %= b;
    }
    cout << res << endl;
  }
  return 0;
}
