#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, t;
  cin >> a >> b;
  cout << (((b * (b - 1) / 2) % 1000000007) *
           ((a + (a * (a + 1) / 2) % 1000000007 * b) % 1000000007)) %
              1000000007
       << endl;
}
