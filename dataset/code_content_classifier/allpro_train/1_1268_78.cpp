#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[5];
  map<long long, long long> m;
  long long i, ans = 0, j;
  for (i = 0; i < 5; i++) {
    cin >> a[i];
    if (m.find(a[i]) != m.end())
      m[a[i]]++;
    else
      m[a[i]] = 1;
    ans += a[i];
  }
  j = ans;
  for (i = 0; i < 5; i++) {
    if (m[a[i]] >= 2) {
      long long l;
      l = m[a[i]];
      j = min(j, ans - a[i] * min(3ll, l));
    }
  }
  cout << j;
  return 0;
}
