#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    long long prev = 0;
    int counter = 0;
    for (int i = 1; i <= n; i += 2) {
      long long a = i * 4;
      a -= 4;
      sum += a * counter;
      counter++;
    }
    cout << sum << endl;
  }
  return 0;
}
