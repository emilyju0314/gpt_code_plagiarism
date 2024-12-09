#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, count;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    j = 1;
    count = i = 0;
    while (i < n) {
      if (a[i] <= j) {
        i++;
        j++;
      } else {
        count += a[i] - j;
        j = a[i] + 1;
        i++;
      }
    }
    cout << count << endl;
  }
}
