#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int N, S;
pair<int, int> ans[MAXN];
pair<int, int> buffer[MAXN];
int len;
int main() {
  priority_queue<pair<int, int> > q;
  scanf("%d %d", &N, &S);
  int x;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &x);
    if (x > 0) q.push(make_pair(x, i));
  }
  bool bingo = true;
  while (!q.empty()) {
    pair<int, int> tmp = q.top();
    q.pop();
    int l = 0;
    while (tmp.first && !q.empty()) {
      pair<int, int> t = q.top();
      q.pop();
      ans[len++] = make_pair(tmp.second, t.second);
      t.first--;
      tmp.first--;
      if (t.first > 0) {
        buffer[l++] = t;
      }
    }
    if (tmp.first > 0) {
      bingo = false;
      break;
    }
    for (int i = 0; i < l; i++) q.push(buffer[i]);
  }
  if (!bingo) {
    puts("No");
    return 0;
  }
  puts("Yes");
  printf("%d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
