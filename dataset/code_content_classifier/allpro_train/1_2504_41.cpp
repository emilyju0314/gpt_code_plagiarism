#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> Bar;

int main() {
  int n, m, h, k;
  while(cin >> n >> m >> h >> k, n | m | h | k) {
    vector<int> s(n);
    for(auto& i: s) cin >> i;

    set<Bar> bar;
    for(int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      bar.insert(Bar(b, a- 1, a));
    }

    vector<int> original(n), goal(n);
    iota(begin(original), end(original), 0);

    set<tuple<int, int>> replaceable;

    for(const auto& i: bar) {
      int z, x, y;
      tie(z, x, y) = i;
      replaceable.insert(tuple<int, int>(min(original[x], original[y]), max(original[x], original[y])));
      swap(original[x], original[y]);
    }
    for(int i = 0; i < n; ++i) goal[original[i]] = i;

    int sum = 0;
    for(int i = 0; i < k; ++i) sum += s[goal[i]];
    int answer = sum;
    for(const auto& i: replaceable) {
      int x, y;
      tie(x, y) = i;
      if(k <= x) break;
      if(y < k) continue;
      answer = min(answer, sum - s[goal[x]] + s[goal[y]]);
    }
    cout << answer << endl;
  }
}