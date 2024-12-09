#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
int n;
vector<int> vec1, vec2;
bool vis[maxn];
int a[maxn];
bool judge(vector<int> &vec) {
  if (vec.size() == 1 || vec.size() == 2)
    return true;
  else if (vec.size() == 0)
    return false;
  int d = vec[1] - vec[0];
  int now = vec[1] + d;
  for (int i = 2; i < vec.size(); i++) {
    if (vec[i] != now) return false;
    now += d;
  }
  return true;
}
bool check(int x, int y) {
  for (int i = 1; i <= n; i++) vis[i] = false;
  vec1.clear();
  vec2.clear();
  int d = a[y] - a[x];
  vec1.push_back(a[x]);
  vec1.push_back(a[y]);
  int now = a[y] + d;
  vis[x] = true;
  vis[y] = true;
  int last = y;
  for (int i = y + 1; i <= n; i++) {
    if (a[i] == now) {
      vis[i] = true;
      now += d;
      vec1.push_back(a[i]);
      last = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vec2.push_back(a[i]);
  }
  if (judge(vec2)) {
    for (int i = 0; i < vec1.size(); i++) printf("%d ", vec1[i]);
    printf("\n");
    for (int i = 0; i < vec2.size(); i++) printf("%d ", vec2[i]);
    printf("\n");
    return true;
  }
  vis[last] = false;
  vec1.pop_back();
  vec2.clear();
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vec2.push_back(a[i]);
  }
  if (judge(vec2)) {
    for (int i = 0; i < vec1.size(); i++) printf("%d ", vec1[i]);
    printf("\n");
    for (int i = 0; i < vec2.size(); i++) printf("%d ", vec2[i]);
    printf("\n");
    return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 2) {
    printf("%d\n%d\n", a[1], a[2]);
    return 0;
  }
  if (!check(1, 2) && !check(1, 3) && !check(2, 3)) puts("No solution");
  return 0;
}
