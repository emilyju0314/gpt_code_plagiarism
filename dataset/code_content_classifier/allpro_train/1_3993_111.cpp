#include <bits/stdc++.h>
using namespace std;
int n, m;
char ch[800005];
int len;
int mxl[800005], mxr[800005], mnl[800005], mnr[800005], sq[800005], tr[800005],
    sum[800005];
int ld[800005], rd[800005];
int lc[800005], rc[800005];
void pushup(int k) {
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
  mxl[k] = max(mxl[k << 1], sum[k << 1] + mxl[k << 1 | 1]);
  mnl[k] = min(mnl[k << 1], sum[k << 1] + mnl[k << 1 | 1]);
  mxr[k] = max(mxr[k << 1 | 1], sum[k << 1 | 1] + mxr[k << 1]);
  mnr[k] = min(mnr[k << 1 | 1], sum[k << 1 | 1] + mnr[k << 1]);
  ld[k] = max(ld[k << 1],
              max(sq[k << 1] + mxl[k << 1 | 1], ld[k << 1 | 1] - sum[k << 1]));
  rd[k] = max(rd[k << 1 | 1],
              max(sq[k << 1 | 1] - mnr[k << 1], sum[k << 1 | 1] + rd[k << 1]));
  sq[k] = max(sq[k << 1] + sum[k << 1 | 1], sq[k << 1 | 1] - sum[k << 1]);
  tr[k] = max(max(tr[k << 1], tr[k << 1 | 1]),
              max(ld[k << 1 | 1] - mnr[k << 1], rd[k << 1] + mxl[k << 1 | 1]));
}
void build(int k, int L, int r) {
  int mid = (L + r) >> 1;
  lc[k] = L;
  rc[k] = r;
  if (L == r) {
    int v = (ch[L] == '(') ? 1 : -1;
    sum[k] = v;
    ld[k] = rd[k] = sq[k] = tr[k] = 1;
    mxl[k] = mxr[k] = max(v, 0);
    mnl[k] = mnr[k] = min(v, 0);
    return;
  }
  build(k << 1, L, mid);
  build(k << 1 | 1, mid + 1, r);
  pushup(k);
}
void modify(int k, int x) {
  if (rc[k] < x || lc[k] > x) return;
  if (lc[k] == rc[k]) {
    int v = (ch[x] == '(') ? 1 : -1;
    sum[k] = v;
    ld[k] = rd[k] = sq[k] = tr[k] = 1;
    mxl[k] = mxr[k] = max(v, 0);
    mnl[k] = mnr[k] = min(v, 0);
    return;
  }
  modify(k << 1, x);
  modify(k << 1 | 1, x);
  pushup(k);
}
int main() {
  int i, j, x, y;
  cin >> n >> m;
  scanf("%s", ch + 1);
  len = strlen(ch + 1);
  build(1, 1, len);
  printf("%d\n", tr[1]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    swap(ch[x], ch[y]);
    modify(1, x);
    modify(1, y);
    printf("%d\n", tr[1]);
  }
  return 0;
}
