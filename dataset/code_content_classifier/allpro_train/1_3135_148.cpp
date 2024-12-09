#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using namespace std;
const ll mod = 1e9 + 7;
const int N = 3e5 + 5;
void test_case() {
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (pair<int, int>& i : vp) cin >> i.first >> i.second;
  sort(vp.begin(), vp.end());
  int year = vp[0].first, k = 1, mx = 1;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(vp[0].second);
  for (int i = 1; i < n; i++) {
    int l = vp[i].first, r = vp[i].second;
    while (!pq.empty() && l >= pq.top()) {
      k--;
      pq.pop();
    }
    k++;
    pq.push(r);
    if (k > mx) {
      mx = k;
      year = l;
    }
  }
  cout << year << " " << mx;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  test_case();
  return 0;
}
