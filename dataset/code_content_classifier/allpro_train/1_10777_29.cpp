#include <bits/stdc++.h>
using namespace std;
vector<long long> tree;
int MaxVal;
long long read(int idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, long long val) {
  while (idx <= MaxVal) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  MaxVal = 4 * n - 1;
  tree = vector<long long>(4 * n, 0);
  for (int i = 1; i <= n; i++) {
    update(i, 1);
  }
  int L, R;
  L = 1;
  R = n;
  bool flipped = false;
  while (q--) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      int p;
      scanf("%d", &p);
      int len = R - L + 1;
      if (p > len - p) {
        p = len - p;
        if (flipped) {
          L += p;
          vector<long long> add(p);
          for (int i = 0; i < p; i++) {
            add[i] = read(L - 1 - i) - read(L - 2 - i);
            update(L + i, add[i]);
          }
          for (int i = 0; i < p; i++) {
            update(L - 1 - i, -add[i]);
          }
        } else {
          R -= p;
          vector<long long> add(p);
          for (int i = 0; i < p; i++) {
            add[i] = read(R + 1 + i) - read(R + i);
            update(R - i, add[i]);
          }
          for (int i = 0; i < p; i++) {
            update(R + 1 + i, -add[i]);
          }
        }
        flipped = !flipped;
      } else {
        if (!flipped) {
          L += p;
          vector<long long> add(p);
          for (int i = 0; i < p; i++) {
            add[i] = read(L - 1 - i) - read(L - 2 - i);
            update(L + i, add[i]);
          }
          for (int i = 0; i < p; i++) {
            update(L - 1 - i, -add[i]);
          }
        } else {
          R -= p;
          vector<long long> add(p);
          for (int i = 0; i < p; i++) {
            add[i] = read(R + 1 + i) - read(R + i);
            update(R - i, add[i]);
          }
          for (int i = 0; i < p; i++) {
            update(R + 1 + i, -add[i]);
          }
        }
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      if (!flipped)
        printf("%I64d\n", read(L + r - 1) - read(L + l - 1));
      else {
        printf("%I64d\n", read(R - l) - read(R - r));
      }
    }
  }
}
