#include <bits/stdc++.h>
using namespace std;
const long long inf = (1LL << 58LL);
long long F[6];
long long sreca[10] = {0, 0, 0, 1, 0, 0, 2, 0, 0, 3};
long long des[6] = {1, 10, 100, 1000, 10000, 100000};
long long rjesenje[1000005];
int main() {
  int K;
  cin >> K;
  int N = 999999;
  for (int i = 0; i < 6; i++) {
    cin >> F[i];
  }
  fill(rjesenje, rjesenje + N + 1, -inf);
  rjesenje[0] = 0;
  for (int i = 0; i < 6; i++) {
    long long lijevo = 3 * (K - 1);
    long long group = 1;
    while (lijevo > 0) {
      group = min(group, lijevo);
      long long vrijednost = group * F[i];
      long long mas = group * des[i] * 3;
      for (int j = N; j >= mas; j--) {
        rjesenje[j] = max(rjesenje[j], rjesenje[j - mas] + vrijednost);
      }
      lijevo -= group;
      group *= 2;
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = N; j >= 0; j--) {
      for (int k = 1; k < 10; k++) {
        int pre = j - des[i] * k;
        if (pre < 0) break;
        rjesenje[j] = max(rjesenje[j], rjesenje[pre] + sreca[k] * F[i]);
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    cout << rjesenje[n] << endl;
    ;
  }
}
