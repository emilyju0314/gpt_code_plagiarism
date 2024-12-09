#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n;
  cin >> n;
  i = n * (n + 1) / 2;
  if (i % 2 == 0)
    cout << 0;
  else
    cout << 1;
  return 0;
}
