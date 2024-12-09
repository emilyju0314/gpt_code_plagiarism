#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  string s, t;
  cin >> n >> k >> s >> t;
  long long c = 0;
  long long working_set = 1;
  for (int i = 0; i < n; i++) {
    working_set *= 2;
    if (s[i] == t[i])
      --working_set;
    else if (s[i] == 'b' && t[i] == 'a')
      working_set -= 2;
    if (working_set > k) {
      c += k * (n - i);
      break;
    }
    c += working_set;
  }
  cout << c << "\n";
  return 0;
}
