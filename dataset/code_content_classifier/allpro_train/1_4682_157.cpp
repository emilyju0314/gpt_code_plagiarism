#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long ans = 0;
  long long ans2 = 0;
  int prob[9];
  for (int i = 0; i < 9; i++) {
    prob[i] = 0;
  }
  for (int i = 1; i <= N; i++) {
    ans += N / i;
    prob[i % 9]++;
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      long long annew = prob[i];
      annew *= prob[j];
      annew *= prob[(i * j) % 9];
      ans2 += annew;
    }
  }
  ans2 -= ans;
  cout << ans2 << endl;
  return 0;
}
