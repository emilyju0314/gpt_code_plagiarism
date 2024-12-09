#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
long long a, b, ans = 1;
int main() {
  cin >> b >> a;
  for (int i = a + 1; i >= 1; i--) cout << i << " ";
  for (int i = a + 2; i <= a + b + 1; i++) cout << i << " ";
  return 0;
}
