#include <bits/stdc++.h>
using namespace std;
struct block {
  int l;
  int r;
  int a[3 * 320];
  int cnt[100002];
};
block bl[320 + 40];
int blocks = 1;
int rebld[100002];
int getcount(int l, int r, int k) {
  int res = 0;
  int curb = 0;
  while (l > bl[curb].r) curb++;
  int curl = bl[curb].l;
  for (int i = 0, to = bl[curb].r - bl[curb].l + 1; i < to; i++, curl++) {
    if (l > r) break;
    if (curl == l) {
      if (bl[curb].a[i] == k) res++;
      l++;
    }
  }
  if (l > r) return res;
  curb++;
  while (bl[curb].r < r) {
    res += bl[curb].cnt[k];
    l = bl[curb].r + 1;
    curb++;
  }
  curl = bl[curb].l;
  for (int i = 0, to = r - l + 1; i < to; i++, curl++) {
    if (l > r) break;
    if (curl == l) {
      if (bl[curb].a[i] == k) res++;
      l++;
    }
  }
  return res;
}
void erase(int b, int idx) {
  bl[b].cnt[bl[b].a[idx]]--;
  int l = bl[b].r - bl[b].l + 1;
  for (int i = idx + 1; i < l; i++) {
    bl[b].a[i - 1] = bl[b].a[i];
  }
  bl[b].r--;
  for (int i = b + 1; i < blocks; i++) {
    bl[i].l--;
    bl[i].r--;
  }
}
void insert(int b, int idx, int v) {
  bl[b].cnt[v]++;
  int l = bl[b].r - bl[b].l + 1;
  for (int i = l; i > idx; i--) {
    bl[b].a[i] = bl[b].a[i - 1];
  }
  bl[b].a[idx] = v;
  bl[b].r++;
  for (int i = b + 1; i < blocks; i++) {
    bl[i].l++;
    bl[i].r++;
  }
}
void update(int l, int r) {
  if (l == r) return;
  int curb = 0;
  while (l > bl[curb].r) curb++;
  int lblock = curb;
  int li = 0;
  for (int i = 0, to = bl[curb].r - bl[curb].l + 1; i < to; i++) {
    if (i + bl[curb].l == l) {
      li = i;
      break;
    }
  }
  while (bl[curb].r < r) curb++;
  int rblock = curb;
  int ri = 0;
  for (int i = 0, to = bl[curb].r - bl[curb].l + 1; i < to; i++) {
    if (i + bl[curb].l == r) {
      ri = i;
      break;
    }
  }
  int ins = bl[rblock].a[ri];
  erase(rblock, ri);
  insert(lblock, li, ins);
}
void rebuild() {
  int k = 0;
  for (int i = 0; i < blocks; i++) {
    for (int j = 0, to = bl[i].r - bl[i].l + 1; j < to; j++) {
      rebld[k++] = bl[i].a[j];
      bl[i].cnt[bl[i].a[j]] = 0;
    }
  }
  int curblock = 0;
  int count = 0;
  bl[curblock].l = 0;
  for (int i = 0; i < k; i++) {
    if (count == 320) {
      curblock++;
      count = 0;
      bl[curblock].l = i;
    }
    bl[curblock].a[count] = rebld[i];
    bl[curblock].cnt[bl[curblock].a[count]]++;
    bl[curblock].r = i;
    count++;
  }
}
void print_mas() {
  for (int i = 0; i < blocks; i++) {
    cout << "[ ";
    for (int j = 0, to = bl[i].r - bl[i].l + 1; j < to; j++) {
      cout << bl[i].a[j] << ",";
    }
    cout << "](" << bl[i].l << "," << bl[i].r << ") ";
  }
  cout << "\n";
}
int main() {
  int n, m;
  scanf("%d", &n);
  int curblock = 0;
  int count = 0;
  bl[curblock].l = 0;
  for (int i = 0; i < n; i++) {
    if (count == 320) {
      curblock++;
      count = 0;
      bl[curblock].l = i;
      blocks++;
    }
    scanf("%d", &bl[curblock].a[count]);
    bl[curblock].cnt[bl[curblock].a[count]]++;
    bl[curblock].r = i;
    count++;
  }
  scanf("%d", &m);
  int a, b, c, k;
  int step = 0;
  int lastans = 0;
  for (int i = 0; i < m; i++) {
    if (step == 320) {
      rebuild();
      step = 0;
    }
    scanf("%d", &c);
    if (c == 1) {
      scanf("%d%d", &a, &b);
      a = ((a + lastans - 1) % n) + 1;
      b = ((b + lastans - 1) % n) + 1;
      if (a > b) swap(a, b);
      update(a - 1, b - 1);
      step++;
    } else {
      scanf("%d%d%d", &a, &b, &k);
      a = ((a + lastans - 1) % n) + 1;
      b = ((b + lastans - 1) % n) + 1;
      k = ((k + lastans - 1) % n) + 1;
      if (a > b) swap(a, b);
      lastans = getcount(a - 1, b - 1, k);
      printf("%d\n", lastans);
    }
  }
  return 0;
}
