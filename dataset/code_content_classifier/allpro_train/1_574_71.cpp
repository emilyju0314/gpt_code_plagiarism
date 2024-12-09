#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > adj;
long long int x1, x2, i, f, z, p, n, t, mc, mv, val[1000000], cal[1000000];
long long int bg(long long int a, long long int b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x1 >> x2;
  for (i = 0; i < n; i++) {
    cin >> t;
    adj.push_back(pair<long long int, long long int>(t, i));
  }
  sort(adj.begin(), adj.end());
  for (i = 0; i < n; i++) {
    cal[i] = i + bg(x1, adj[i].first) - 1;
    val[i] = i + bg(x2, adj[i].first) - 1;
  }
  mc = mv = 1e9;
  for (i = 0; i < n; i++) {
    mc = min(mc, cal[i]);
    mv = min(mv, val[i]);
    if (mc < i && val[i] < n) {
      f = 1;
      p = i;
      break;
    }
    if (mv < i && cal[i] < n) {
      f = 2;
      p = i;
      break;
    }
  }
  if (f == 1) {
    cout << "Yes" << endl;
    for (i = 0; i < n; i++) {
      if (cal[i] == mc) {
        z = i;
        break;
      }
    }
    cout << mc - z + 1 << " ";
    cout << val[p] - p + 1 << endl;
    for (i = z; i <= mc; i++) cout << adj[i].second + 1 << " ";
    cout << endl;
    for (i = p; i <= val[p]; i++) cout << adj[i].second + 1 << " ";
    cout << endl;
  }
  if (f == 2) {
    cout << "Yes" << endl;
    for (i = 0; i < n; i++) {
      if (val[i] == mv) {
        z = i;
        break;
      }
    }
    cout << cal[p] - p + 1 << " ";
    cout << mv - z + 1 << endl;
    for (i = p; i <= cal[p]; i++) cout << adj[i].second + 1 << " ";
    cout << endl;
    for (i = z; i <= mv; i++) cout << adj[i].second + 1 << " ";
    cout << endl;
  }
  if (f == 0) cout << "No" << endl;
  return 0;
}
