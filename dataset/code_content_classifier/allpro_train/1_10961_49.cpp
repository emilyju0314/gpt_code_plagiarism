#include <bits/stdc++.h>
using namespace std;
long long a[100009];
int main() {
  long long n, m;
  cin >> n >> m;
  long long i, j;
  string s;
  map<string, long long> mp1, mp2;
  for (i = 0; i < n; i++) {
    cin >> s;
    mp1[s]++;
  }
  long long c = 0;
  for (i = 0; i < m; i++) {
    cin >> s;
    if (mp1.find(s) != mp1.end()) {
      c++;
    }
    mp2[s]++;
  }
  long long x = n - c;
  long long y = m - c;
  if (x > y) {
    cout << "YES";
  } else if (x < y) {
    cout << "NO";
  } else {
    if (c % 2 == 0) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  }
}
