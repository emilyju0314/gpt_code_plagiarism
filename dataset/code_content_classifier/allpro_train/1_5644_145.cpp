#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int A[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long cc = 0;
    long long n = 9;
    while (n <= b) {
      cc++;
      n = n * 10 + 9;
    }
    cout << cc * a << '\n';
  }
  return 0;
}
