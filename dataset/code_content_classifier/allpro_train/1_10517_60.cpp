#include <bits/stdc++.h>
using namespace std;
int m = 1000000007;
int main() {
  long long int a, b, n;
  cin >> a >> b >> n;
  long long int s[] = {a, b, b - a, -a, -b, a - b};
  cout << (s[(n - 1) % 6] % m + m) % m;
  return 0;
}
