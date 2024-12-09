#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n, k;
    cin >> n >> k;
    long long ds = 1;
    long long chiso = 0, chiso1 = 0;
    while (n > (long long)pow(2, chiso)) {
      chiso++;
    }
    while (k > (long long)pow(2, chiso1)) {
      chiso1++;
    }
    if (k >= n) {
      cout << chiso << "\n";
    } else {
      if (n <= (long long)pow(2, chiso1)) {
        cout << chiso1 << "\n";
        continue;
      } else {
        long long m = pow(2, chiso1);
        n -= m;
        if (n % k == 0)
          cout << chiso1 + n / k << "\n";
        else
          cout << chiso1 + n / k + 1 << "\n";
      }
    }
  }
  return 0;
}
