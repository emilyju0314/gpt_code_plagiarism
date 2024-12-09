#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int markX[N];
vector<int> dv[N];
int get(int x, int y, int w) {
  int cnt = (int)dv[x].size();
  int l = w - y;
  for (int i = 0; i < dv[x].size(); i++) {
    int cur = dv[x][i];
    if (markX[cur] >= l) cnt--;
  }
  return cnt;
}
void insert(int x, int w) {
  for (int i = 0; i < dv[x].size(); i++) {
    int cur = dv[x][i];
    markX[cur] = w;
  }
}
int main() {
  for (int i = 1; i < N; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        dv[i].push_back(j);
        if (j * j != i) {
          dv[i].push_back(i / j);
        }
      }
    }
    sort(dv[i].begin(), dv[i].end());
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", get(x, y, i));
    insert(x, i);
  }
}
