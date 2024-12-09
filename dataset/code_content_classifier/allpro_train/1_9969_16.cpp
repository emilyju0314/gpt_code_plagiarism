#include <bits/stdc++.h>
using namespace std;
int v[10];
int main() {
  int n;
  cin >> n;
  int a = n / 10, b = n % 10;
  v[1] = v[7] = v[9] = 1;
  if (n == 12) {
    cout << "YES\n";
    return 0;
  }
  if (v[a] || v[b] || a == 2)
    cout << "NO\n";
  else
    cout << "YES\n";
}
