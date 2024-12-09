#include <bits/stdc++.h>
const int NMAX = 200005;
using namespace std;
int N;
int p[NMAX + 2], q[NMAX + 2], v[NMAX + 2], answer[NMAX + 2];
void update(int place) {
  for (int i = place; i <= N; i += (i & -i)) {
    ++v[i];
  }
}
int query(int place) {
  int ans = 0;
  for (int i = place; i; i -= (i & -i)) {
    ans += v[i];
  }
  return ans;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> p[i];
    ++p[i];
    update(p[i]);
    p[i] = p[i] - query(p[i]);
  }
  memset(v, 0, sizeof v);
  for (int i = 1; i <= N; ++i) {
    cin >> q[i];
    ++q[i];
    update(q[i]);
    q[i] = q[i] - query(q[i]);
  }
  for (int i = N - 1; i >= 1; --i) {
    answer[i] += p[i] + q[i];
    if (answer[i] >= N - i + 1) {
      answer[i] -= (N - i + 1);
      ++answer[i - 1];
    }
  }
  memset(v, 0, sizeof v);
  for (int i = 1; i <= N; ++i) {
    int left = 1, right = N, last = -1;
    while (left <= right) {
      int middle = (left + right) / 2;
      if (middle - query(middle) >= answer[i] + 1) {
        last = middle;
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    cout << last - 1 << (i == N ? '\n' : ' ');
    update(last);
  }
  return 0;
}
