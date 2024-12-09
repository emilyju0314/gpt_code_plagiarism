#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
int n;
vector<pair<int, int> > tv;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  tv.resize(n);
  map<int, int> mn;
  for (int i = 0; i < n; i++) {
    cin >> tv[i].first >> tv[i].second;
    mn[tv[i].first] = mn[tv[i].second] = 0;
    mn[tv[i].first + 1] = mn[tv[i].second + 1] = 0;
  }
  int c = 0;
  for (auto& i : mn) i.second = c++;
  vector<int> cnt(c + 1);
  for (int i = 0; i < n; i++) {
    tv[i].first = mn[tv[i].first];
    tv[i].second = mn[tv[i].second];
    cnt[tv[i].first]++;
    cnt[tv[i].second + 1]--;
  }
  for (int i = 0, cur = 0; i < c + 1; i++) {
    cur += cnt[i];
    cnt[i] = cur == 1;
  }
  for (int i = 1; i < c + 1; i++) cnt[i] += cnt[i - 1];
  bool f = false;
  for (int i = 0; i < n; i++)
    if (tv[i].first && cnt[tv[i].second] - cnt[tv[i].first - 1] == 0 ||
        cnt[tv[i].second] == 0) {
      f = true;
      cout << i + 1 << endl;
      break;
    }
  if (!f) cout << -1 << endl;
  cin.ignore(), cin.get();
}
