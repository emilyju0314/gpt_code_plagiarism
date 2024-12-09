#include <bits/stdc++.h>
using namespace std;
void readin() {}
void init() {}
void process() {}
void writeout() {}
void make() { freopen("in.txt", "wt", stdout); }
int main() {
  readin();
  init();
  process();
  writeout();
  int n, k, a[111];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<int, int> > s;
  for (int i = 0; i < k; i++) {
    int min = 0, max = 0;
    for (int j = 0; j < n; j++) {
      min = (a[j] < a[min]) ? j : min;
      max = (a[j] > a[max]) ? j : max;
    }
    if (a[max] - a[min] <= 1) break;
    if (min != max) {
      a[max]--;
      a[min]++;
      s.push_back(make_pair(max, min));
    }
  }
  int min = 222222, max = 0;
  for (int j = 0; j < n; j++) {
    min = (a[j] < min) ? a[j] : min;
    max = (a[j] > max) ? a[j] : max;
  }
  cout << max - min << " " << s.size() << endl;
  for (int i = 0; i < s.size(); i++)
    cout << s[i].first + 1 << " " << s[i].second + 1 << endl;
  return 0;
}
