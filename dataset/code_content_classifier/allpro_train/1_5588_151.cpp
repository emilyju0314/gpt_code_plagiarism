#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005], cost[2][200005], mn, d1[200005], d2[200005];
long long n, m, k, s;
bool cal(long long x, long long y) {
  long long totalCost = 0;
  long long taken = 0;
  vector<long long> v;
  for (long long i = 1; i <= m; i++) {
    if (cost[0][i]) v.push_back(cost[0][i] * x);
  }
  for (long long i = 1; i <= m; i++) {
    if (cost[1][i]) v.push_back(cost[1][i] * y);
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    if (((totalCost + v[i]) <= s) && (taken < k)) {
      taken++;
      totalCost += v[i];
    } else {
      break;
    }
  }
  if (taken == k) return true;
  return false;
}
void printSolution(int mid) {
  int mnX, mnY;
  for (int i = 1; i <= mid; i++) {
    if (d1[i] == a[mid]) {
      mnX = i;
    }
    if (d2[i] == b[mid]) {
      mnY = i;
    }
  }
  vector<pair<long long, pair<long long, int> > > v;
  for (long long i = 1; i <= m; i++) {
    if (cost[0][i]) v.push_back({cost[0][i] * a[mnX], {i, 0}});
  }
  for (long long i = 1; i <= m; i++) {
    if (cost[1][i]) v.push_back({cost[1][i] * b[mnY], {i, 1}});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < k; i++) {
    cout << v[i].second.first << " ";
    if (v[i].second.second == 0)
      cout << mnX << endl;
    else
      cout << mnY << endl;
  }
  return;
}
int main() {
  cin >> n >> m >> k >> s;
  mn = INT_MAX;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    d1[i] = x;
    mn = min(mn, x);
    a[i] = mn;
  }
  mn = INT_MAX;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    d2[i] = x;
    mn = min(mn, x);
    b[i] = mn;
  }
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    cost[x - 1][i] = y;
  }
  long long hi, lo, mid;
  lo = 1, hi = n;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (lo == hi) {
      mid = lo;
      break;
    }
    if (cal(a[mid], b[mid])) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  if (!cal(a[mid], b[mid])) {
    cout << -1 << endl;
  } else {
    cout << mid << endl;
    printSolution(mid);
  }
  return 0;
}
