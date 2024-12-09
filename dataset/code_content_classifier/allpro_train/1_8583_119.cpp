#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, max = 0;
  unsigned long long res = 0;
  cin >> n;
  unordered_map<int, int> m;
  while (n--) {
    cin >> x;
    res += x;
    if (max < x) max = x;
  }
  if (!(res % 2) && max <= (res - max)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
