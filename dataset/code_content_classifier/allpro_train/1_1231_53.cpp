#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int INF = 2e9;
int T;
int main() {
  cin >> T;
  while (T--) {
    int n, a, b, ha, i;
    cin >> n;
    for (i = 2; i * (i - 1) / 2 <= n; i++)
      ;
    cout << 133;
    i--;
    n -= i * (i - 1) / 2;
    for (int j = 1; j <= n; j++) cout << 7;
    for (int j = 1; j <= i - 2; j++) cout << 3;
    cout << 7 << "\n";
  }
}
