#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, hob;
  cin >> hob;
  vector<vector<int> > hobbits;
  vector<pair<int, int> > days;
  int pos;
  for (int i = 1; i < 10000; i++) {
    if (i * (i - 1) / 2 > hob) {
      n = i - 1;
      break;
    }
  }
  cout << n << endl;
  days.resize(n * (n - 1) / 2);
  pos = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      days[pos++] = make_pair(i, j);
    }
  hobbits.resize(n + 1);
  for (int i = 0; i < days.size(); i++) {
    hobbits[days[i].first].push_back(i + 1);
    hobbits[days[i].second].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    if (hobbits[i].size()) {
      cout << hobbits[i][0];
      for (int j = 1; j < hobbits[i].size(); j++) {
        cout << ' ' << hobbits[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
