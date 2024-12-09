#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string myname;
  cin >> myname;
  string name1, action, x, name2;
  int n;
  cin >> n;
  map<string, int> priority;
  for (int i = 0; i < n; i++) {
    cin >> name1 >> action;
    if (action == "posted" || action == "commented") cin >> x;
    cin >> name2;
    name2 = name2.substr(0, name2.size() - 2);
    cin >> x;
    int factor = 5;
    if (action == "posted") factor = 15;
    if (action == "commented") factor = 10;
    if (name1 == myname)
      priority[name2] += factor;
    else
      priority[name1];
    if (name2 == myname)
      priority[name1] += factor;
    else
      priority[name2];
  }
  vector<pair<int, string>> ans;
  map<string, int>::iterator it;
  for (it = priority.begin(); it != priority.end(); it++)
    ans.push_back(make_pair(-it->second, it->first));
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i].second << endl;
  return 0;
}
