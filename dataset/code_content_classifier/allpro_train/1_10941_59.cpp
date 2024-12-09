#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq_whi, pq_bla;
  for (int i = int(0); i <= int(n - 1); i++) {
    int p, q;
    scanf("%d", &p);
    scanf("%d", &q);
    pair<int, int> u = pair<int, int>(q, i + 1);
    if (p == 0)
      pq_whi.push(u);
    else
      pq_bla.push(u);
  }
  bool ch = true;
  while (!pq_whi.empty() && !pq_bla.empty()) {
    pair<int, int> whi = pq_whi.top();
    pq_whi.pop();
    pair<int, int> bla = pq_bla.top();
    pq_bla.pop();
    if (whi.first > bla.first) {
      printf("%d %d %d\n", whi.second, bla.second, bla.first);
      whi.first -= bla.first;
      pq_whi.push(whi);
      ch = true;
    } else if (whi.first < bla.first) {
      printf("%d %d %d\n", whi.second, bla.second, whi.first);
      bla.first -= whi.first;
      pq_bla.push(bla);
      ch = false;
    } else if ((ch && !pq_bla.empty()) || (!ch && pq_whi.empty())) {
      printf("%d %d %d\n", whi.second, bla.second, whi.first);
      whi.first = 0;
      pq_whi.push(whi);
      ch = !ch;
    } else {
      printf("%d %d %d\n", whi.second, bla.second, whi.first);
      bla.first = 0;
      pq_bla.push(bla);
      ch = !ch;
    }
  }
  return 0;
}
