#include <bits/stdc++.h>
using namespace std;
vector<int> setunion;
int findHead(int a) {
  if (setunion[a] == a) return a;
  return setunion[a] = findHead(setunion[a]);
}
int main() {
  long long n;
  cin >> n;
  vector<long long> qual(n);
  for (long long i{}; i < n; ++i) cin >> qual[i];
  long long m;
  cin >> m;
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
      pq;
  setunion = vector<int>(n);
  for (int i{}; i < n; ++i) setunion[i] = i;
  for (long long i{}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    pq.push({c, a - 1, b - 1});
  }
  long long out{};
  map<int, int> dist;
  while (!pq.empty()) {
    auto v = pq.top();
    pq.pop();
    if (findHead(v[1]) != findHead(v[2])) {
      if (setunion[v[2]] != v[2]) {
        if (v[0] < dist[v[2]]) {
          out -= dist[v[2]];
          out += v[0];
          setunion[v[2]] = setunion[v[1]];
        }
        continue;
      }
      out += v[0];
      setunion[v[2]] = setunion[v[1]];
    }
  }
  for (int i{}; i < n - 1; ++i) {
    if (findHead(i) != findHead(i + 1)) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << out << '\n';
}
