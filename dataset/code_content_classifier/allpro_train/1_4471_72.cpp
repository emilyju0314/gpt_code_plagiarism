#include <bits/stdc++.h>
using namespace std;
int num[200005];
int vis[200005];
int a[200005];
int main() {
  int n;
  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      num[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (num[i] == 0) q.push(i);
    printf("%d\n", q.size());
    for (int i = 1; i <= n; i++) {
      int tmp;
      if (num[a[i]] == 1)
        tmp = a[i];
      else if (q.empty())
        tmp = a[i];
      else if ((!vis[a[i]]) && a[i] < q.front())
        tmp = a[i];
      else {
        tmp = q.front();
        q.pop();
      }
      vis[tmp] = 1;
      if (tmp != a[i]) num[a[i]]--;
      printf("%d\%c", tmp, i == n ? '\n' : ' ');
    }
  }
  return 0;
}
