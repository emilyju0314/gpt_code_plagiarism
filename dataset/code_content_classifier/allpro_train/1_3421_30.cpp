#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int const N = 1e6 + 10, M = 5e6 + 10, oo = 1e9;
const int mod = oo + 7;
const long long OO = 1e18;
int n, aa[20], an[N];
vector<pair<int, int> > ev, od;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = n - 1, d = 1; i > 0; i--, d++) {
    if (d & 1)
      od.push_back({i, d});
    else
      ev.push_back({i, d});
  }
  reverse(od.begin(), od.end());
  reverse(ev.begin(), ev.end());
  for (int i = 0; i < (int)od.size(); i++)
    an[i] = an[i + od[i].second] = od[i].first;
  for (int i = od.empty() ? 0 : od[0].second + 1, j = 0; j < (int)ev.size();
       i++, j++)
    an[i] = an[i + ev[j].second] = ev[j].first;
  for (int i = 0; i < 2 * n; i++) {
    if (!an[i]) an[i] = n;
    cout << an[i] << ' ';
  }
  cout << endl;
  return 0;
}
