#include <bits/stdc++.h>
using namespace std;
int n, a[100];
int main() {
  cin >> n;
  a[0] = 2;
  a[1] = 7;
  a[2] = 2;
  a[3] = 3;
  a[4] = 3;
  a[5] = 4;
  a[6] = 2;
  a[7] = 5;
  a[8] = 1;
  a[9] = 2;
  cout << a[n / 10] * a[n % 10];
}
