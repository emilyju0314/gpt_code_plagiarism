#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, T;
  long long int i, count, n;
  scanf("%d", &T);
  for (t = 0; t < T; t++) {
    cin >> n;
    if (n % 4 == 3)
      cout << n + 1 << endl;
    else if (n % 4 == 1)
      cout << 2 * n + 1 << endl;
    else if (n % 2 == 0)
      cout << 4 * n + 1 << endl;
  }
  return 0;
}
