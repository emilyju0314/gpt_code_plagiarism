#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n], b[n];
    long long i, cnt0 = 0, cnt1 = 0, flag = 1;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] == 1)
        cnt1 = 1;
      else
        cnt0 = 1;
    }
    if (cnt0 == 1 && cnt1 == 1) {
      cout << "Yes" << endl;
      continue;
    }
    for (i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      cout << "Yes" << endl;
    } else if (flag == 0) {
      cout << "No" << endl;
    }
  }
  return 0;
}
