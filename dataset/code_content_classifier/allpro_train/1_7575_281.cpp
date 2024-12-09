#include <bits/stdc++.h>
using namespace std;
long long oo = (long long)1e9;
template <typename T>
using V = vector<T>;
inline void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  long long n, m;
  bool ans = 0;
  cin >> n;
  long long p = -1;
  for (long long i = 0; i < n; i++) {
    cin >> m;
    while (m % 2 == 0) m /= 2;
    while (m % 3 == 0) m /= 3;
    if (p == -1 || m == p) {
      p = m;
    } else if (!ans) {
      cout << "No";
      ans = 1;
    }
  }
  if (!ans) cout << "Yes";
  return 0;
}
