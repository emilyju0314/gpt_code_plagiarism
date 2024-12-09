#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int A = 0, B = 0;
    for (int i = 0; i < n - 1; i++) {
      A += s[i] == '1' && s[i + 1] == '1';
      B += s[i] == '0' && s[i + 1] == '0';
    }
    cout << max(A, B) << "\n";
  }
  return 0;
}
