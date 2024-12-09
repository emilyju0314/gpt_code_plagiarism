#include <bits/stdc++.h>
using namespace std;
const unsigned long long maxa = 1e17;
unsigned long long a[100];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    unsigned long long n, k;
    cin >> n >> k;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      unsigned long long tmp;
      cin >> tmp;
      for (int c = log(maxa) / log(k); c >= 0; c--) {
        while (tmp >= (unsigned long long)pow(k, (unsigned long long)c))
          tmp -= (unsigned long long)pow(k, (unsigned long long)c), a[c]++;
      }
    }
    for (long long i : a)
      if (i > 1) {
        ok = 0;
        break;
      }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
