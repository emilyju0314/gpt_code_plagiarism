#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sum = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (v[i] < v[i + 1])
        sum += v[i];
      else {
        v[i] = v[i + 1] - 1 < 0 ? 0 : v[i + 1] - 1;
        sum += v[i];
      }
    }
    cout << sum << endl;
  }
}
