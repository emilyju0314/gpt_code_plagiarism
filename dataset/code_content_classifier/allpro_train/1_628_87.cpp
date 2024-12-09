#include <bits/stdc++.h>
using namespace std;
long long freq[2002][2002] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, c = 0;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    freq[v[i].first + 1000][v[i].second + 1000]++;
  }
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      long long x = v[i].first + v[j].first, y = v[i].second + v[j].second;
      if (x % 2 || y % 2) continue;
      if (freq[x / 2 + 1000][y / 2 + 1000] >= 1) c++;
    }
  }
  cout << c << "\n";
}
