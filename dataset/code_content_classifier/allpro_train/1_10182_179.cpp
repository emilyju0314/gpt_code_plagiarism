#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
vector<pair<string, int> > v;
int main() {
  ios_base::sync_with_stdio(false);
  int n, i, j, k;
  string s;
  char p[20];
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", p);
    if (p[0] == 'i') {
      scanf("%d", &k);
      s = p;
      q.push(k);
      v.push_back(make_pair(s, k));
    } else if (p[0] == 'r') {
      s = p;
      if (q.empty()) {
        v.push_back(make_pair("insert", 1));
        v.push_back(make_pair(s, 0));
      } else {
        v.push_back(make_pair(s, 0));
        q.pop();
      }
    } else {
      scanf("%d", &k);
      s = p;
      bool flag = 0;
      while (!q.empty()) {
        if (q.top() < k) {
          v.push_back(make_pair("removeMin", 0));
          q.pop();
        } else if (q.top() > k) {
          v.push_back(make_pair("insert", k));
          q.push(k);
          v.push_back(make_pair(s, k));
          flag = 1;
          break;
        } else {
          v.push_back(make_pair(s, k));
          flag = 1;
          break;
        }
      }
      if (!flag) {
        v.push_back(make_pair("insert", k));
        q.push(k);
        v.push_back(make_pair(s, k));
      }
    }
  }
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) {
    cout << v[i].first;
    if (v[i].first != "removeMin") cout << " " << v[i].second;
    cout << endl;
  }
  return 0;
}
