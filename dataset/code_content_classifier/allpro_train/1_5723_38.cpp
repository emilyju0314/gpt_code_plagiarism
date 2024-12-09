#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, k;
  int count = 0;
  cin >> a;
  cin >> b;
  k = a;
  if (b % a == 0) {
    while (k <= b) {
      k = k * a;
      count++;
    }
    k = k / a;
    if ((k - b) == 0)
      cout << "YES\n" << count - 1;
    else
      cout << "NO";
  } else
    cout << "NO";
  return 0;
}
