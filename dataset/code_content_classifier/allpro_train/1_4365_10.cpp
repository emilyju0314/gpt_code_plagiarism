#include <bits/stdc++.h>
using namespace std;
ofstream fo("test.out");
ifstream fi("test.inp");
long long n, m, k, rs, dem;
long long a[100005];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      if (m > 0)
        m--;
      else
        rs++;
    }
    if (a[i] == 2) {
      if (k > 0)
        k--;
      else {
        if (m > 0)
          m--;
        else
          rs++;
      }
    }
  }
  cout << rs;
}
