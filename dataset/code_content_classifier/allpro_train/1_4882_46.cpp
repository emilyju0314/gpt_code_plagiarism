#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int obj;
  scanf("%d", &obj);
  int category[100002];
  int origin[100002];
  int counter[100002];
  queue<int> q;
  for (int i = 1; i <= obj; i++) {
    scanf("%d", &category[i]);
    if (category[i] == 1) {
      q.push(i);
    }
  }
  memset(counter, 0, sizeof(counter));
  int from;
  for (int i = 1; i <= obj; i++) {
    scanf("%d", &from);
    origin[i] = from;
    counter[from]++;
  }
  vector<int> res, temp;
  int maxpath = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int turn = 0;
    temp.clear();
    while (true) {
      turn++;
      temp.push_back(v);
      v = origin[v];
      if (counter[v] > 1 || v == 0) break;
    }
    if (maxpath < turn) {
      maxpath = turn;
      res = temp;
    }
  }
  printf("%d\n", maxpath);
  reverse(res.begin(), res.end());
  for (int i = 0; i < maxpath - 1; i++) {
    printf("%d ", res[i]);
  }
  printf("%d\n", res[maxpath - 1]);
  return 0;
}
