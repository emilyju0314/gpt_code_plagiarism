#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> p(n, 0);
  long long temp;
  vector<int> occ(n, 0);
  p[0] = 1;
  long long min_enc = 1;
  for (long long i = 1; i < n; i++) {
    cin >> temp;
    p[i] = p[i - 1] + temp;
    if (p[i] < min_enc) {
      min_enc = p[i];
    }
  }
  int d = 0;
  for (long long i = 0; i < n; i++) {
    p[i] = p[i] - min_enc + 1;
    if (p[i] > n) {
      d = 1;
      break;
    }
    occ[p[i] - 1]++;
    if (occ[p[i] - 1] > 1) {
      d = 1;
      break;
    }
  }
  if (d == 0) {
    for (long long i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
  } else
    cout << -1 << endl;
  return 0;
}
