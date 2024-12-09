#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  a += b;
  while (a < 0) a += n;
  if (a >= n) a = a % n;
  cout << a + 1;
  return 0;
}
