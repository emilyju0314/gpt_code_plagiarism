#include <bits/stdc++.h>
using namespace std;
int b = -1;
int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.size() - 1; i++) {
    if (!((n[i] - '0') % 2) && n[i] < n[n.size() - 1]) {
      swap(n[i], n[n.size() - 1]);
      cout << n << endl;
      return 0;
    }
    if (!((n[i] - '0') % 2) && n[i] > n[n.size() - 1]) {
      b = i;
    }
  }
  if (b == -1) {
    cout << b << endl;
    return 0;
  }
  swap(n[b], n[n.size() - 1]);
  cout << n << endl;
  return 0;
}
