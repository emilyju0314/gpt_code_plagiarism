#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000;
int a[MaxN];
int l[MaxN], r[MaxN];
vector<int> now;
vector<int> q;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  l[0] = -1;
  r[n - 1] = -1;
  for (int i = 1; i < n; i++)
    if (a[i] < a[i - 1]) now.push_back(i);
  int step = 0;
  while (now.size() != 0) {
    q.clear();
    step++;
    int i = 1;
    int sz = now.size();
    bool doIt = false;
    while (i <= sz) {
      int stFrom = now[i - 1];
      while (i != sz && l[now[i]] == now[i - 1]) i++;
      int upTo = now[i - 1];
      r[l[stFrom]] = r[upTo];
      l[r[upTo]] = l[stFrom];
      if (r[upTo] != -1 && a[l[stFrom]] > a[r[upTo]]) {
        q.push_back(r[upTo]);
      }
      i++;
    }
    now.clear();
    for (int j = 0; j < q.size(); j++) now.push_back(q[j]);
  }
  cout << step;
}
