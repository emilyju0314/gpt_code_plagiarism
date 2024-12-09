#include <bits/stdc++.h>
using namespace std;
const int siz = pow(10, 6) + 1;
bool b[10000001];
long long numOfDiv(long long num) {
  if (num == 1)
    return 1;
  else if (!b[num])
    return 2;
  else {
    long long count = 1;
    for (long long i = 2; i <= num; i++) {
      if (!b[i]) {
        if (num % i == 0) {
          long long ind = 0;
          while (num % i == 0) {
            ind++;
            num /= i;
          }
          count *= (ind + 1);
        }
      }
    }
    return count;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  int precision = numeric_limits<double>::digits10;
  ;
  for (int i = 2; i < siz; i++) {
    if (!b[i]) {
      for (int j = 2 * i; j < siz; j += i) {
        b[j] = true;
      }
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  const long long mod = 1073741824;
  for (int i = 1; i < a + 1; i++) {
    for (int j = 1; j < b + 1; j++) {
      for (int k = 1; k < c + 1; k++) {
        long long temp = i * j * k;
        ans += numOfDiv(temp);
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
}
