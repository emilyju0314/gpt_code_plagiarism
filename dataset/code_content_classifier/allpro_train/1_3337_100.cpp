#include <bits/stdc++.h>
using namespace std;
const int zero = 201, maxn = 507, maxnum = 100000000;
int x, y, n, d;
int dx[maxn], dy[maxn];
int sg[maxn][maxn];
int dis(int x, int y) {
  return (x - zero) * (x - zero) + (y - zero) * (y - zero);
}
int SG(int x, int y) {
  if (dis(x, y) > d) return 1;
  if (sg[x][y] != -1) return sg[x][y];
  vector<int> vec;
  vec.push_back(-1);
  vec.push_back(maxnum);
  for (int i = 1; i <= n; i++) vec.push_back(SG(x + dx[i], y + dy[i]));
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
    if (vec[i] + 1 < vec[i + 1]) return sg[x][y] = vec[i] + 1;
}
void work() {
  x += zero, y += zero;
  d *= d;
  for (int i = 1; i <= n; i++) scanf("%d%d", &dx[i], &dy[i]);
  memset(sg, -1, sizeof(sg));
  printf("%s\n", SG(x, y) ? "Anton" : "Dasha");
}
int main() {
  while (scanf("%d%d%d%d", &x, &y, &n, &d) != EOF) work();
}
