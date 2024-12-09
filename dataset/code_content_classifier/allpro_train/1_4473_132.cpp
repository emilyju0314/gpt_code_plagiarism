#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (n > 27)
    cout << m;
  else {
    int x = pow(2, n);
    x = m % x;
    cout << x;
  }
  return 0;
}
