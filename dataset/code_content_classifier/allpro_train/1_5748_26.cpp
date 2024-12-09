#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, m, n, h;
  cin >> n;
  j = 0;
  vector<long long> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    j += v[i];
  }
  string s1 = "";
  i = 0;
  while (j > 0) {
    if (v[i] > 0 && i + 1 < n) {
      j--;
      s1 += "P";
      v[i]--;
      if (v[i] > 0) {
        if (v[i + 1] > 0 && i + 1 < n) {
          j--;
          s1 += "RPL";
          v[i + 1]--;
        } else if (v[i + 1] == 0) {
          s1 += "RL";
        }
      }
    } else if (v[i] > 0 && i + 1 == n) {
      s1 += "P";
      v[i]--;
      j--;
      if (v[i] > 0) s1 += "LR";
    } else {
      s1 += "R";
      i++;
    }
  }
  cout << s1;
}
