#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, q;
  cin >> k >> q;
  double probs[10 * k + 1][k + 1];
  probs[1][1] = 1;
  double ka = k;
  for (int i = 2; i < 10 * k + 1; i++) {
    probs[i][1] = probs[i - 1][1] / ka;
    for (int j = 2; j < min(i + 1, k + 1); j++) {
      double ja = j;
      probs[i][j] =
          probs[i - 1][j - 1] * (ka + 1 - ja) / ka + probs[i - 1][j] * ja / ka;
    }
  }
  for (int i = 0; i < q; i++) {
    double prob;
    cin >> prob;
    prob /= 2000;
    int j = k;
    while (probs[j][k] < prob) {
      ++j;
    }
    cout << j << endl;
  }
}
