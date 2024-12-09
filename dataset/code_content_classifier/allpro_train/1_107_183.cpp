#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
  ;
  cin >> a >> b >> c;
  cout << (c * a + b - 1) / b - c;
}
