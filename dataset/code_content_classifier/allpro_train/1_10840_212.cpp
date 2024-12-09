#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a[3];
    for (long long int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    sort(a, a + 3);
    reverse(a, a + 3);
    long long int c = 0;
    for (long long int i = 0; i < 3; i++) {
      for (long long int j = i; j < 3; j++) {
        if (a[i] > 0 & a[j] > 0) {
          if (i == j) {
            a[i]--;
            c++;
          } else {
            c++;
            a[i]--;
            a[j]--;
          }
        }
      }
    }
    if (a[0] > 0 & a[1] > 0 & a[2] > 0) c++;
    cout << c << endl;
  }
}
