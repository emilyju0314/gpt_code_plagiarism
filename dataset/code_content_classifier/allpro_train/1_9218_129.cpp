#include <bits/stdc++.h>
using namespace std;
bool gone[200004];
int main() {
  int n, boys = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) boys += (s[i] == 'B');
  int arr[n];
  map<int, pair<int, int> > mp;
  mp[0] = {1, -1};
  mp[n - 1] = {n - 2, -1};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i && i != n - 1) mp[i] = {i + 1, i - 1};
  }
  priority_queue<pair<int, pair<int, int> > > pq;
  for (int i = 0; i < n - 1; i++)
    pq.push({-abs(arr[i] - arr[i + 1]), {-i, -(i + 1)}});
  cout << min(boys, n - boys) << '\n';
  while (pq.size()) {
    pair<int, pair<int, int> > p;
    p.first = pq.top().first;
    p.second.first = -pq.top().second.first;
    p.second.second = -pq.top().second.second;
    pq.pop();
    if (gone[p.second.first] || gone[p.second.second]) continue;
    if (s[p.second.first] == s[p.second.second]) continue;
    if (p.second.first == -1 || p.second.second == -1) continue;
    cout << min(p.second.first + 1, p.second.second + 1) << ' '
         << max(p.second.first + 1, p.second.second + 1) << '\n';
    gone[p.second.first] = gone[p.second.second] = 1;
    int other1, other2;
    other1 = mp[p.second.first].first;
    if (other1 == p.second.second) other1 = mp[p.second.first].second;
    other2 = mp[p.second.second].first;
    if (other2 == p.second.first) other2 = mp[p.second.second].second;
    int o1, o2;
    o1 = mp[other1].first;
    if (o1 == p.second.first) o1 = mp[other1].second;
    o2 = mp[other2].first;
    if (o2 == p.second.second) o2 = mp[other2].second;
    mp[other1] = {other2, o1};
    mp[other2] = {other1, o2};
    pq.push({-abs(arr[other1] - arr[other2]), {-other1, -other2}});
  }
  return 0;
}
