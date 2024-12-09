#include <bits/stdc++.h>
using namespace std;
long long n, m, v, vt[100005];
vector<pair<int, int>> edgeList;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> v;
  if (m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    vt[i] = i;
  }
  swap(vt[v], vt[n - 1]);
  for (int i = 1; i < n; i++) {
    edgeList.push_back(make_pair(vt[i], vt[i + 1]));
  }
  int i = 1, j = 3;
  while (edgeList.size() != m) {
    edgeList.push_back(make_pair(vt[i], vt[j]));
    j++;
    if ((i < n - 1 && j > n - 1) || (i >= n - 1 && j > m)) {
      i++;
      j = i + 2;
    }
  }
  for (int i = 0; i < edgeList.size(); i++) {
    cout << edgeList[i].first << " " << edgeList[i].second << '\n';
  }
  return 0;
}
