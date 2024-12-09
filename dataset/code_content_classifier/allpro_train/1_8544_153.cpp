#include <bits/stdc++.h>
using namespace std;
pair<string, int> get_project() {
  string str;
  int a;
  cin >> str >> a;
  return make_pair(str, a);
}
bool comp(pair<string, int> a, pair<string, int> b) {
  return (a.first < b.first) || ((a.first == b.first) && (a.second < b.second));
}
pair<string, int> del = make_pair("#", 0);
int main() {
  map<pair<string, int>, vector<pair<string, int> >,
      bool (*)(pair<string, int>, pair<string, int>)>
      arr(comp);
  pair<string, int> a, tmp, tmp2;
  int n;
  string str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    tmp = get_project();
    if (i == 0) {
      a = tmp;
    }
    arr[tmp] = vector<pair<string, int> >();
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      tmp2 = get_project();
      arr[tmp].push_back(tmp2);
    }
    getline(cin, str);
  }
  queue<pair<string, int> > q;
  map<string, int> ans;
  q.push(a);
  while (q.size() > 0) {
    q.push(del);
    while (q.front() != del) {
      tmp = q.front();
      q.pop();
      if ((ans.find(tmp.first) == ans.end()) ||
          ((ans[tmp.first] < 0) && (-ans[tmp.first] < tmp.second))) {
        ans[tmp.first] = -tmp.second;
      }
    }
    q.pop();
    for (auto it = ans.begin(), en(ans.end()); it != en; it++) {
      if (it->second < 0) {
        it->second *= -1;
        for (auto it2 = arr[*it].begin(), en(arr[*it].end()); it2 != en;
             it2++) {
          if (ans.find(it2->first) == ans.end()) {
            q.push(*it2);
          }
        }
      }
    }
  }
  ans.erase(a.first);
  cout << ans.size() << endl;
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}
