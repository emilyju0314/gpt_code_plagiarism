#include <bits/stdc++.h>
const int N = 1000007, inf = 0x3f3f3f3f;
using namespace std;
int d[N];
int sai[N];
vector<pair<int, int> > edges;
void no() {
  cout << "NO\n";
  exit(0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> borders;
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    if (d[i] == 1 and tot >= 2) borders.push_back(i);
    tot += d[i] == 1;
  }
  deque<int> g;
  priority_queue<pair<int, int> > pq;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > 1) g.push_back(i);
    pq.push(pair<int, int>(d[i], i));
  }
  int flag = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 1) {
      if (flag == 0)
        g.push_front(i);
      else
        g.push_back(i);
      flag = 1;
    }
  }
  for (int x : borders) {
    sai[x] = 1;
    if (pq.size() == 0) no();
    pair<int, int> aux = pq.top();
    pq.pop();
    int d = aux.first, u = aux.second;
    if (d <= 2) no();
    edges.emplace_back(u, x);
    pq.push(pair<int, int>(d - 1, u));
  }
  int last = -1;
  for (int x : g) {
    if (sai[x]) continue;
    if (last != -1) edges.emplace_back(last, x);
    last = x;
  }
  cout << "YES"
       << " " << n - int(borders.size()) - 1 << endl;
  cout << edges.size() << endl;
  for (pair<int, int> x : edges) {
    cout << x.first << " " << x.second << endl;
  }
}
