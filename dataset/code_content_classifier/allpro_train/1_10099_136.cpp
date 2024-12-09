#include <bits/stdc++.h>
using namespace std;
bool wayToSort(pair<int, int> i, pair<int, int> j) { return i.first > j.first; }
vector<pair<int, int> > res;
pair<int, int> limit_pos[1000];
int n, informed[1000];
int main() {
  int i, j;
  informed[0]++;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> limit_pos[i].first;
    limit_pos[i].second = i + 1;
  }
  sort(limit_pos + 1, limit_pos + n, wayToSort);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n && limit_pos[i].first > 0; j++) {
      if (!informed[j]) {
        informed[j]++;
        limit_pos[i].first--;
        res.push_back(make_pair(limit_pos[i].second, limit_pos[j].second));
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (informed[i] == 0) {
      cout << -1;
      return 0;
    }
  }
  cout << res.size() << endl;
  for (i = 0; i < res.size(); i++) {
    cout << res[i].first << ' ' << res[i].second << endl;
  }
}
