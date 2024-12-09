#include <bits/stdc++.h>
using namespace std;
const int INPUT_MAXCHARS = 1 << 16;
char buffer[INPUT_MAXCHARS];
struct FastReader {
  char *p;
  FastReader() : p(buffer) { fread(buffer, 1, sizeof buffer, stdin); }
  int next_int() {
    int remchars = INPUT_MAXCHARS - (p - buffer);
    if (remchars < 25) {
      memcpy(buffer, p, remchars);
      size_t cnt = fread(buffer + remchars, 1, sizeof buffer - remchars, stdin);
      if (remchars + cnt < sizeof buffer) {
        buffer[remchars + cnt] = 0;
      }
      p = buffer;
    }
    while (*p < '0') {
      p++;
    }
    int val = 0;
    while (*p >= '0') {
      val = val * 10 + (*p - '0');
      ++p;
    }
    return val;
  }
};
const int MAXPOW = 1 << 20;
vector<int> T[2 * MAXPOW];
const int MAXN = 1000000;
int revP[MAXN], revQ[MAXN];
int query(int x, int a, int b, int l1, int r1, int l2, int r2) {
  if (a >= r1 || b <= l1) return 0;
  if (l1 <= a && b <= r1) {
    return lower_bound(T[x].begin(), T[x].end(), r2) -
           lower_bound(T[x].begin(), T[x].end(), l2);
  } else {
    return query(2 * x, a, (a + b) / 2, l1, r1, l2, r2) +
           query(2 * x + 1, (a + b) / 2, b, l1, r1, l2, r2);
  }
}
int main() {
  FastReader reader;
  int n = reader.next_int();
  for (int i = 0; i < n; ++i) {
    int x = reader.next_int();
    revP[x - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    int x = reader.next_int();
    revQ[x - 1] = i;
  }
  int sz = 1;
  while (sz < n) {
    sz *= 2;
  }
  for (int i = 0; i < n; ++i) {
    T[sz + revP[i]].push_back(revQ[i]);
  }
  for (int i = sz - 1; i > 0; --i) {
    int left = 2 * i;
    int right = left + 1;
    merge(T[left].begin(), T[left].end(), T[right].begin(), T[right].end(),
          back_inserter(T[i]));
  }
  int Q = reader.next_int();
  int x = 0;
  while (Q--) {
    int a = reader.next_int();
    int b = reader.next_int();
    int c = reader.next_int();
    int d = reader.next_int();
    int l1 = min((a - 1 + x) % n, (b - 1 + x) % n);
    int r1 = max((a - 1 + x) % n, (b - 1 + x) % n);
    int l2 = min((c - 1 + x) % n, (d - 1 + x) % n);
    int r2 = max((c - 1 + x) % n, (d - 1 + x) % n);
    x = query(1, 0, sz, l1, r1 + 1, l2, r2 + 1);
    cout << x << '\n';
    ++x;
  }
  return 0;
}
