#include <bits/stdc++.h>
using namespace std;
inline void init() { ios::sync_with_stdio(false); }
map<long long int, long long int> qnt;
vector<pair<long long int, long long int> > memo;
int main() {
  init();
  long long int n, m;
  cin >> n >> m;
  long long int band[n + 1], ans = n / m, mins = 0;
  for (int i = 1, _ = m + 1; i < _; i++) qnt[i] = 0;
  for (int i = 1, _ = n + 1; i < _; i++) {
    cin >> band[i];
    if (!qnt[band[i]]) qnt[band[i]] = 0;
    qnt[band[i]]++;
  }
  for (int i = 1, _ = m + 1; i < _; i++) {
    if (qnt[i] < ans) {
      memo.push_back(pair<long long int, long long int>(i, ans - qnt[i]));
      mins += abs(ans - qnt[i]);
    }
  }
  long long int at = 0, tam = memo.size();
  for (int i = 1, _ = n + 1; i < _; i++) {
    if (at == mins) break;
    if (qnt[band[i]] > ans || band[i] > m) {
      qnt[band[i]]--;
      band[i] = memo[tam - 1].first;
      qnt[band[i]]++;
      memo[tam - 1].second -= 1;
      if (memo[tam - 1].second == 0) tam--;
      at++;
    }
  }
  cout << ans << ' ' << mins;
  cout << '\n';
  for (int i = 1, _ = n + 1; i < _; i++) cout << band[i] << ' ';
  return 0;
}
