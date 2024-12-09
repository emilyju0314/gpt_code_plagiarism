#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), cmp);
  int ans = 0;
  int fim = -1;
  for (int i = 0; i < n; i++) {
    if (v[i].first > fim) {
      fim = v[i].second;
      ans++;
    }
  }
  cout << ans << '\n';
  exit(0);
}
