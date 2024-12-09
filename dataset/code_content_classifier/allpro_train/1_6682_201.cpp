#include <bits/stdc++.h>
using namespace std;
const long long int mxn = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int i, j, k, n, m;
    string s;
    cin >> s;
    n = s.length();
    string a, b, c;
    i = -1;
    j = n;
    while ((i + 1) < (j - 1) && s[i + 1] == s[j - 1]) {
      a += s[i + 1];
      i++, j--;
    }
    c = a;
    reverse(c.begin(), c.end());
    long long int pr = -1, sf = -1;
    for (long long int i1 = i + 1; i1 < j; i1++) {
      long long int st = i + 1, en = i1;
      while (st <= en && s[st] == s[en]) st++, en--;
      if (st > en) pr = i1;
    }
    for (long long int i1 = i + 1; i1 < j; i1++) {
      long long int st = i1, en = j - 1;
      while (st <= en && s[st] == s[en]) st++, en--;
      if (st > en) {
        sf = i1;
        break;
      }
    }
    if (pr != -1) {
      if (pr - i > j - sf) {
        for (long long int i1 = i + 1; i1 <= pr; i1++) b += s[i1];
      } else {
        for (long long int i1 = sf; i1 < j; i1++) b += s[i1];
      }
    }
    cout << a << b << c << "\n";
  }
  return 0;
}
