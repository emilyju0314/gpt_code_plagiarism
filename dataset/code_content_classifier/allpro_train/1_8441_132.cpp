#include <bits/stdc++.h>
using namespace std;
struct app {
  int pos, prev, next;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<app> v(n + 1);
  int p = 0;
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (p) v[p].next = x;
    v[x] = {i, p, 0};
    p = x;
  }
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    result += v[b].pos / k + 1;
    if (v[b].prev) {
      int prev = v[b].prev;
      int pprev = v[prev].prev;
      int next = v[b].next;
      v[pprev].next = b;
      v[prev].prev = b;
      v[prev].next = next;
      v[prev].pos++;
      v[b].prev = pprev;
      v[b].pos--;
      v[b].next = prev;
      v[next].prev = prev;
    }
  }
  cout << result << endl;
}
