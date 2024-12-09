#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > days;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    pair<int, int> cP;
    cin >> cP.first >> cP.second;
    days.push_back(cP);
  }
  int sum = 0;
  for (int i = 0; i < n;) {
    sum += days[i].first * days[i].second;
    int j;
    for (j = i + 1; (j < n) && (days[i].second < days[j].second); ++j) {
      sum += days[j].first * days[i].second;
    }
    i = j;
  }
  cout << sum << endl;
  return 0;
}
