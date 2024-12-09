#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b;
  int map[1000001];
  int app[1000001];
  for (long long i = (0); i < (1000001); ++i) map[i] = -1, app[i] = 0;
  cin >> n;
  for (long long i = (0); i < (n); ++i) {
    cin >> a >> b;
    app[a]++;
    app[b]++;
    map[a] = b;
  }
  vector<int> reteven;
  vector<int> retodd;
  int tg = 0;
  while (app[tg] > 1 && map[tg] > 0) {
    reteven.push_back(map[tg]);
    tg = map[tg];
  }
  for (long long i = (0); i < (1000001); ++i) {
    if (app[i] == 1 && map[i] != -1) {
      tg = i;
      retodd.push_back(i);
      while (map[tg] > 0) {
        retodd.push_back(map[tg]);
        tg = map[tg];
      }
      break;
    }
  }
  for (long long i = (0); i < (n / 2); ++i) {
    if (i != 0) cout << " ";
    cout << retodd[i] << " " << reteven[i];
  }
  if (n % 2 == 1) cout << " " << retodd[n / 2];
  cout << "\n";
}
