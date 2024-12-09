#include <bits/stdc++.h>
using namespace std;
template <class T>
int len(const T& c) {
  return (int)c.size();
}
int main() {
  int n, bb;
  double b1;
  vector<double> b;
  cin >> n >> bb;
  for (int i(0), _n(n); i < _n; ++i) {
    cin >> b1;
    b.push_back(b1);
  }
  double sum = accumulate(b.begin(), b.end(), 0);
  double mx = *max_element(b.begin(), b.end());
  double avg = (sum + bb) / n;
  if (mx > avg) {
    cout << -1;
    return 0;
  }
  for (int i(0), _n(n); i < _n; ++i) printf("%.6f\n", avg - b[i]);
}
