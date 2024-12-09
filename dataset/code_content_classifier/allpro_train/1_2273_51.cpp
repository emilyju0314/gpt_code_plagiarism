#include <bits/stdc++.h>
using namespace std;
struct s_ix {
  long long n, ix;
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, a[1000];
    cin >> n;
    for (int j = 0; j < n; j++) cin >> a[j];
    sort(a, a + n);
    long long err = 0;
    for (int j = 1; j < n; j++) {
      if (a[j] - a[j - 1] > 1) err = 1;
    }
    if (err == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
