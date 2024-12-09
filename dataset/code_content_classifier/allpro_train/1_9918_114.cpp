#include <bits/stdc++.h>
using namespace std;
vector<int> tasks[105];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 0; i < n; i++) {
    int t, q;
    scanf("%d%d", &t, &q);
    tasks[t].push_back(q);
  }
  for (int i = 1; i < T; i++) {
    if (tasks[i].size() > 0) {
      sort(tasks[i].begin(), tasks[i].end(), greater<int>());
      for (int j = 0; j < tasks[i].size(); j += 2) {
        if (j + 1 < tasks[i].size())
          tasks[i + 1].push_back(tasks[i][j] + tasks[i][j + 1]);
        else
          tasks[i + 1].push_back(tasks[i][j]);
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < tasks[T].size(); i++) mx = max(tasks[T][i], mx);
  printf("%d\n", mx);
}
