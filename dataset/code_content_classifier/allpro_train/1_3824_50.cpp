#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int odd1 = 0, odd2 = 0, n, m, temp, i;
    vector<long long int> p;
    vector<long long int> q;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> temp;
      p.push_back(temp);
      if (temp % 2 != 0) odd1++;
    }
    cin >> m;
    for (i = 0; i < m; i++) {
      cin >> temp;
      q.push_back(temp);
      if (temp % 2 != 0) odd2++;
    }
    cout << odd1 * odd2 + (p.size() - odd1) * (q.size() - odd2) << endl;
  }
  return 0;
}
