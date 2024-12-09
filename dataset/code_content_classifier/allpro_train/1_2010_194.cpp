#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> in(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      in[i] = (pow(2, i));
    }
    long long sum = in[n];
    int z = 1;
    while (z != n / 2) {
      sum += in[z];
      z++;
    }
    for (size_t i = n / 2; i < n; i++) {
      sum -= in[i];
    }
    cout << sum << endl;
  }
}
