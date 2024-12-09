#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int a[N], b[N], c[2 * N];
vector<int> vec[N];
int boy[N], girl[N], used[N];
bool find(int x, int sign) {
  for (auto i : vec[x])
    if (boy[i] == 0) {
      boy[i] = x;
      return true;
    }
  for (auto i : vec[x]) {
    if (used[i] == sign) continue;
    used[i] = sign;
    if (find(boy[i], sign)) {
      boy[i] = x;
      return true;
    }
  }
  return false;
}
template <typename T>
inline void read(T &x) {
  int f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    read(b[i]);
    c[2 * i - 1] = a[i];
    c[2 * i] = b[i];
  }
  sort(c + 1, c + 2 * n + 1);
  int len = unique(c + 1, c + 2 * n + 1) - c - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(c + 1, c + len + 1, a[i]) - c;
    b[i] = lower_bound(c + 1, c + len + 1, b[i]) - c;
    vec[a[i]].push_back(i);
    vec[b[i]].push_back(i);
  }
  int ans = 0;
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= len; i++) {
    if (find(i, i)) ans++;
    if (ans == n) {
      printf("%d", c[i]);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
