#include <bits/stdc++.h>
using namespace std;
bool is[110000];
int a, m;
int main() {
  while (cin >> a >> m) {
    a %= m;
    memset(is, 0, sizeof(is));
    for (int i = a % m; is[i] == false; i = (2 * i) % m) is[i] = true;
    if (is[0])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
