#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n;
int c[maxn];
vector<int> nexts[maxn];
int indeg[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    c[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", indeg + i);
    for (int j = 0; j < indeg[i]; j++) {
      int ai;
      scanf("%d", &ai);
      ai--;
      nexts[ai].push_back(i);
    }
  }
  int ret = 1 << 30;
  for (int s = 0; s < 3; s++) {
    int hours = 0;
    queue<int> Q[3];
    vector<int> deg(indeg, indeg + n);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        Q[c[i]].push(i);
      }
    }
    int house = s;
    while (!Q[0].empty() || !Q[1].empty() || !Q[2].empty()) {
      if (Q[house].empty()) {
        hours++;
        house = (house + 1) % 3;
        continue;
      }
      int p = Q[house].front();
      Q[house].pop();
      hours++;
      for (int i = 0; i < nexts[p].size(); i++) {
        int q = nexts[p][i];
        if (--deg[q] == 0) {
          Q[c[q]].push(q);
        }
      }
    }
    ret = min(ret, hours);
  }
  printf("%d\n", ret);
}
