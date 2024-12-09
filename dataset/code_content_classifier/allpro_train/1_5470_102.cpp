#include <bits/stdc++.h>
using namespace std;
long long fact(int n, int k) {
  long long sum = 1;
  for (int i = 1; i <= k; i++) {
    sum = sum * n;
    sum = sum / i;
    n--;
  }
  return sum;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  long long sum = 0;
  int k = c - 4;
  if (b == 1 && a + b == c) {
    cout << b << endl;
    return 0;
  } else if (a <= b && a + b == c) {
    cout << 1 << endl;
    return 0;
  } else {
    for (int i = 4, j = k; i < 4 + k, j >= 1; i++, j--) {
      sum = sum + ((fact(a, i) * (fact(b, j))));
    }
    cout << sum << endl;
  }
}
