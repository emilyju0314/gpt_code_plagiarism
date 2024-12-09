#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> ob[1000];
  pair<int, int> clues[1000];
  for (int i = 0; i < n; i++) cin >> ob[i].first >> ob[i].second;
  for (int i = 0; i < n; i++) cin >> clues[i].first >> clues[i].second;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      mp[{ob[j].first + clues[i].first, ob[j].second + clues[i].second}]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second >= n) {
      cout << (it->first).first << " " << (it->first).second;
      break;
    }
  }
  return 0;
}
