#include <bits/stdc++.h>
using namespace std;
int i, j, k;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ;
    long long int a[n];
    map<int, int> m;
    int flag = 0;
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      m[a[i]]++;
      if (m[a[i]] > 1) flag = 1;
    }
    if (flag)
      cout << "YES";
    else {
      int cnt = 0;
      for (int i = (0); i < (n - 1); i++) {
        if (a[i] > a[i + 1]) cnt++;
      }
      if (cnt == n - 1)
        cout << "NO";
      else
        cout << "YES";
    }
    cout << "\n";
  }
}
