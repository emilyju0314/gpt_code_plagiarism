#include <bits/stdc++.h>
using namespace std;
int n;
int mid;
int a[30];
int b[30];
int c[30];
int num[30];
int res = -(int)2e9;
int m1, m2;
pair<int, int> para;
map<pair<int, int>, pair<int, int> > have;
map<pair<int, int>, pair<int, int> >::iterator it;
void calcF(int x) {
  int px = x;
  memset(num, 0, sizeof(num));
  int pos = 0;
  while (x > 0) {
    num[++pos] = x % 3;
    x /= 3;
  }
  pos = mid;
  int L, M, W;
  L = M = W = 0;
  for (int i = 1; i <= pos; i++) {
    if (num[i] == 0) {
      L += a[i];
      M += b[i];
    } else if (num[i] == 1) {
      L += a[i];
      W += c[i];
    } else {
      M += b[i];
      W += c[i];
    }
  }
  it = have.find(make_pair(L - M, M - W));
  if (it == have.end()) {
    have.insert(make_pair(make_pair(L - M, M - W), make_pair(px, L)));
  } else {
    para = it->second;
    if (para.second < L) {
      para = make_pair(px, L);
    }
    have[make_pair(L - M, M - W)] = para;
  }
}
void calcS(int x) {
  int px = x;
  memset(num, 0, sizeof(num));
  int pos = 0;
  while (x > 0) {
    num[++pos] = x % 3;
    x /= 3;
  }
  pos = n - mid;
  int L, M, W;
  L = M = W = 0;
  for (int i = 1; i <= pos; i++) {
    if (num[i] == 0) {
      L += a[i + mid];
      M += b[i + mid];
    } else if (num[i] == 1) {
      L += a[i + mid];
      W += c[i + mid];
    } else {
      M += b[i + mid];
      W += c[i + mid];
    }
  }
  it = have.find(make_pair(M - L, W - M));
  if (it == have.end()) {
    return;
  }
  para = it->second;
  if (para.second + L > res) {
    res = para.second + L;
    m1 = para.first;
    m2 = px;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  mid = (n + 1) / 2;
  int maxN = 1;
  for (int i = 1; i <= mid; i++) {
    maxN *= 3;
  }
  int other = 1;
  for (int i = 1; i <= n - mid; i++) {
    other *= 3;
  }
  for (int i = 0; i <= maxN; i++) {
    calcF(i);
  }
  for (int i = 0; i <= other; i++) {
    calcS(i);
  }
  if (res == -(int)2e9) {
    puts("Impossible");
    return 0;
  }
  memset(num, 0, sizeof(num));
  int pos = 0;
  while (m1 > 0) {
    num[++pos] = m1 % 3;
    m1 /= 3;
  }
  pos = mid;
  while (m2 > 0) {
    num[++pos] = m2 % 3;
    m2 /= 3;
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == 0) {
      puts("LM");
    } else if (num[i] == 1) {
      puts("LW");
    } else
      puts("MW");
  }
  return 0;
}
