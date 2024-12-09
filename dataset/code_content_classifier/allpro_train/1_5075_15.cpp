#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  bool v = false;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 1 and a[0] % 2 == 1 and a[n - 1] % 2 == 1)
    puts("Yes");
  else
    puts("No");
  return 0;
}
