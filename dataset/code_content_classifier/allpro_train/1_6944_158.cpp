#include <bits/stdc++.h>
using namespace std;
vector<long long> push(long long a, long long n, long long d) {
  vector<long long> res(n);
  for (int i = 0; i < n; i++) res[i] = a + (i)*d;
  return res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, x, y;
    cin >> a >> x >> y;
    long long pp = y - x;
    vector<long long> fac;
    vector<long long> best(a, 0);
    for (int i = 1; i <= 50; i++) {
      if (pp % i == 0) fac.push_back(i);
    }
    long long last = 1e12, common = 0, start = 0;
    vector<long long> qq;
    for (int j = 1; j <= x; j++) {
      for (int i = 1; i <= 50; i++) {
        bool presentx = false, presenty = false;
        qq = push(j, a, i);
        for (int k = 0; k < a; k++) {
          if (qq[k] == x) presentx = true;
          if (qq[k] == y) presenty = true;
        }
        if (presentx && presenty) {
          if (qq[a - 1] < last) {
            last = qq[a - 1];
            start = j;
            common = i;
          }
        }
      }
    }
    for (int i = 0; i < a; i++) cout << start + i * common << " ";
    cout << "\n";
  }
}
