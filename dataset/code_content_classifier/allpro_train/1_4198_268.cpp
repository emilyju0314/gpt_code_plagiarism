#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1 << 17];
set<pair<int, pair<int, int> > > S;
vector<pair<int, int> > E;
int D[1 << 17], SUM[1 << 17];
int R[1 << 17];
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d, sum, i, j, u, x;
  pair<int, pair<int, int> > t;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> d >> sum;
    D[i] = d;
    SUM[i] = sum;
  }
  for (i = 0; i < n; i++)
    if (D[i] == 1)
      S.insert(pair<int, pair<int, int> >(D[i], pair<int, int>(i, SUM[i])));
  while (!S.empty()) {
    t = *S.begin();
    S.erase(S.begin());
    u = t.second.first;
    d = t.first;
    sum = t.second.second;
    if (graph[u].size() == d) continue;
    x = R[u] ^ sum;
    graph[x].push_back(u);
    graph[u].push_back(x);
    R[x] = R[x] ^ u;
    if (graph[x].size() == D[x] - 1)
      S.insert(pair<int, pair<int, int> >(D[x], pair<int, int>(x, SUM[x])));
    E.push_back(pair<int, int>(x, u));
  }
  cout << E.size() << "\n";
  for (i = 0; i < E.size(); i++)
    cout << E[i].first << " " << E[i].second << "\n";
  return 0;
}
