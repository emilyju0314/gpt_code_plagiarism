#include <bits/stdc++.h>
using namespace std;
bool judge(int n, int k) {
  if (k % 3 != 0) return n % 3 != 0;
  n %= k + 1;
  return n == k || n % 3 != 0;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    if (judge(n, k)) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
  return 0;
}
