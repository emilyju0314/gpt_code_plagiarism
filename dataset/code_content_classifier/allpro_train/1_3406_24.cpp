#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, a, b, ans = 0;
  cin >> N;
  int pow[16];
  pow[0] = 1;
  for (int i = 1; i <= 15; i++) pow[i] = pow[i - 1] * 4;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    for (int j = 0; j <= 15; j++)
      if (pow[j] >= b) {
        if (b == 1)
          ans = max(ans, a + j + 1);
        else
          ans = max(ans, a + j);
        break;
      }
  }
  cout << ans << endl;
  return 0;
}
