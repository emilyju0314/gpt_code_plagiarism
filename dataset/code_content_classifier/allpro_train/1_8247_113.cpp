#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n;
long long sum;
int col[maxn << 1], lst[maxn << 1], a[maxn << 1];
vector<int> v[maxn << 1];
void dfs(int x, int c) {
  col[x] = c;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (col[y] == 0) dfs(y, 3 - c);
  }
}
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    puts("First");
    fflush(stdout);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    puts("");
    return 0;
  }
  puts("Second");
  fflush(stdout);
  for (int i = 1; i <= (n << 1); i++) {
    scanf("%d", &a[i]);
    if (lst[a[i]] == 0)
      lst[a[i]] = i;
    else
      v[i].push_back(lst[a[i]]), v[lst[a[i]]].push_back(i);
  }
  for (int i = 1; i <= n; i++) v[i].push_back(n + i), v[n + i].push_back(i);
  for (int i = 1; i <= (n << 1); i++) {
    if (col[i] == 0) dfs(i, 1);
    if (col[i] == 1) sum += i;
  }
  int ok = sum % (2 * n) == 0 ? 1 : 2;
  for (int i = 1; i <= (n << 1); i++)
    if (col[i] == ok) printf("%d ", i);
  puts("");
  return 0;
}
