#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long int, int> &a, pair<long long int, int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } else
    return a.first < b.first;
}
int main() {
  long long T = 1;
  for (int t = 1; t <= T; t++) {
    long long int n, c;
    cin >> n;
    c = n;
    long long a = 0, b = 1, ans = 0;
    while (b <= n) {
      long long int c = a + b;
      a = b;
      b = c;
      ans++;
    }
    cout << ans - 2 << endl;
  }
  return 0;
}
