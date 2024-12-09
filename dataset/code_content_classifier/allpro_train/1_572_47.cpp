#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<char> v(n, 'o');
  v[0] = 'O';
  int val1 = 0;
  int val2 = 1;
  while (val2 <= n) {
    int x = val2;
    val2 = val1 + val2;
    val1 = x;
    if (val2 - 1 < n) {
      v[val2 - 1] = 'O';
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
  cout << endl;
  return 0;
}
