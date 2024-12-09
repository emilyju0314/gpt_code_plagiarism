#include <bits/stdc++.h>
using namespace std;
FILE *in = stdin, *out = stdout;
int a[1000005], mem[1000005 * 2];
long long int ans[1000005];
int n, w, B, last;
void input() {
  fscanf(in, "%d", &n), fscanf(in, "%d", &w);
  B = 1;
  while (B < w) B *= 2;
  B--;
}
void pro() {
  for (int i = (1); i <= (n); i++) {
    int m;
    fscanf(in, "%d", &m);
    int Max = 0;
    for (int j = (1); j <= (m); j++) {
      fscanf(in, "%d", &a[j]);
      Max = max(Max, a[j]);
    }
    for (int j = (1); j <= (m * 2); j++) {
      mem[j] = -1000000007;
      if (w - j + 1 >= 0) mem[w - j + 1] = -1000000007;
    }
    deque<int> dq;
    for (int j = (1); j <= (min(w, m * 2)); j++) {
      if (j <= m) {
        while (!dq.empty() && a[dq.back()] <= a[j]) {
          dq.pop_back();
        }
        dq.push_back(j);
      }
      while (!dq.empty() && w - (m - dq.front()) < j) dq.pop_front();
      int t = a[dq.front()];
      if (t < 0) {
        if (j <= w - m) t = 0;
      }
      mem[j] = max(mem[j], t);
    }
    while (!dq.empty()) dq.pop_back();
    for (int j = m, k = w; k >= max(1, w - m * 2 + 1); j--, k--) {
      if (j >= 1) {
        while (!dq.empty() && a[dq.back()] <= a[j]) {
          dq.pop_back();
        }
        dq.push_back(j);
      }
      while (!dq.empty() && dq.front() > k) dq.pop_front();
      int t = a[dq.front()];
      if (t < 0) {
        if (k >= m + 1) t = 0;
      }
      mem[k] = max(mem[k], t);
    }
    if (w > m * 2) {
      for (int j = (1); j <= (m); j++) ans[j] += mem[j], ans[j + 1] -= mem[j];
      for (int j = (1); j <= (m); j++)
        ans[w - j + 1] += mem[w - j + 1], ans[w - j + 2] -= mem[w - j + 1];
      ans[m + 1] += Max;
      ans[w - m + 1] -= Max;
    } else {
      for (int j = (1); j <= (w); j++) ans[j] += mem[j], ans[j + 1] -= mem[j];
    }
  }
  for (int i = (1); i <= (w); i++) {
    ans[i] += ans[i - 1];
    fprintf(out, "%lld ", ans[i]);
  }
}
int main() {
  input();
  pro();
  return 0;
}
