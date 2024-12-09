#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[100000], b[100000], c[100000];
pair<int, int> task[100000];
pair<int, pair<int, int> > st[100000];
int who[100000];
bool test(int days) {
  long long cost = 0;
  priority_queue<pair<int, pair<int, int> > > stud;
  int ptr = 0;
  for (int i = 0; i < m; i++) {
    while (ptr < n && st[ptr].first >= task[i].first) {
      stud.push(make_pair(-st[ptr].second.first,
                          make_pair(days, st[ptr].second.second)));
      ptr++;
    }
    if (stud.empty()) return false;
    pair<int, pair<int, int> > tmp = stud.top();
    stud.pop();
    who[task[i].second] = tmp.second.second + 1;
    cost -= tmp.first;
    tmp.second.first--;
    tmp.first = 0;
    if (tmp.second.first) stud.push(tmp);
  }
  return (cost <= (long long)s);
}
int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    task[i] = make_pair(a[i], i);
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    st[i] = make_pair(b[i], make_pair(c[i], i));
  }
  sort(task, task + m);
  reverse(task, task + m);
  sort(st, st + n);
  reverse(st, st + n);
  int l = 1, r = m + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (test(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (r > m) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  test(l);
  for (int i = 0; i < m; i++) cout << who[i] << " ";
  return 0;
}
