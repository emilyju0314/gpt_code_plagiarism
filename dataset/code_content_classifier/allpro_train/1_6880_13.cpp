#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const int maxv = 1000000000;
long long int A[maxn];
int n, q;
vector<long long int> bucket[10000];
long long int val[10000];
int koliko;
void makebuc() {
  int b = sqrt(n);
  for (int i = 0; i <= b + 100; i++) {
    for (int j = i * b; j < (i + 1) * b && j < n; j++) {
      bucket[i].push_back(A[j]);
    }
  }
  for (int i = 0;; i++) {
    if (bucket[i].size() == 0) break;
    sort(bucket[i].begin(), bucket[i].end());
  }
}
void update(int l, int r, int x) {
  int b = sqrt(n);
  int pos1 = l / b;
  bucket[pos1].clear();
  for (int i = l; i < b * (pos1 + 1) && i <= r; i++) {
    if (A[i] + x > maxv)
      A[i] = maxv + 1;
    else
      A[i] += x;
  }
  for (int i = b * pos1; i < b * (pos1 + 1) && i < n; i++)
    bucket[pos1].push_back(A[i]);
  sort(bucket[pos1].begin(), bucket[pos1].end());
  for (int i = pos1 + 1; (i + 1) * b - 1 < r; i++) {
    if (val[i] + x > maxv)
      val[i] = maxv + 1;
    else
      val[i] += x;
  }
  int pos2 = r / b;
  if (pos1 == pos2) return;
  bucket[pos2].clear();
  for (int i = b * pos2; i <= r; i++) {
    if (A[i] + x > maxv)
      A[i] = maxv + 1;
    else
      A[i] += x;
  }
  for (int i = b * pos2; i < b * (pos2 + 1) && i < n; i++)
    bucket[pos2].push_back(A[i]);
  sort(bucket[pos2].begin(), bucket[pos2].end());
}
bool jel(int pos, int x) {
  if (val[pos] == -1) return 0;
  int broj = x - val[pos];
  if (broj < 0) return 0;
  if (*(lower_bound(bucket[pos].begin(), bucket[pos].end(), broj)) == broj)
    return 1;
  return 0;
}
int fja(int x) {
  int l = -1, r = -1;
  int b = sqrt(n);
  for (int i = 0;; i++) {
    if (bucket[i].size() == 0) break;
    if (jel(i, x)) {
      l = i;
      break;
    }
  }
  if (l == -1) return l;
  for (int i = koliko; i >= 0; i--) {
    if (bucket[i].size() == 0) continue;
    if (jel(i, x)) {
      r = i;
      break;
    }
  }
  for (int i = l * b; i < n; i++)
    if (A[i] + val[i / b] == x) {
      l = i;
      break;
    }
  for (int i = min(n - 1, (r + 1) * b - 1); i >= 0; i--)
    if (A[i] + val[i / b] == x) {
      r = i;
      break;
    }
  return r - l;
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  makebuc();
  for (int i = 0;; i++) {
    if (bucket[i].size() == 0) break;
    koliko++;
  }
  for (int i = 0; i < q; i++) {
    int a;
    scanf("%d", &a);
    if (a == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l--;
      r--;
      update(l, r, x);
    }
    if (a == 2) {
      int y;
      scanf("%d", &y);
      printf("%d\n", fja(y));
    }
  }
  return 0;
}
