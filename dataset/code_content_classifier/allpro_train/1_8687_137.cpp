#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int root[maxn + 11];
int tree[40 * maxn + 11], ls[40 * maxn + 11], rs[40 * maxn + 11];
int x[maxn + 11], y[maxn + 11], num[maxn + 11], a[maxn + 11];
vector<int> vec[maxn + 11], hor[maxn + 11];
vector<int> X, Y;
int sumx[maxn + 11], sumy[maxn + 11];
bool flag = false;
int n;
bool vis[100];
int tot = 0;
int query(int rt, int l, int r, int al, int ar) {
  if (l > ar || r < al) return 0;
  if (l >= al && r <= ar) return tree[rt];
  int mid = (l + r) >> 1;
  return query(ls[rt], l, mid, al, ar) + query(rs[rt], mid + 1, r, al, ar);
}
bool check(int x1, int x2, int y1, int y2) {
  int cnt[10];
  cnt[1] = query(root[x1 + 1], 1, Y.size(), 1, y1 + 1);
  cnt[2] = query(root[x2 + 1], 1, Y.size(), 1, y1 + 1) - cnt[1];
  cnt[3] = sumy[y1] - cnt[1] - cnt[2];
  cnt[4] = query(root[x1 + 1], 1, Y.size(), y1 + 2, y2 + 1);
  cnt[5] = query(root[x2 + 1], 1, Y.size(), y1 + 2, y2 + 1) - cnt[4];
  cnt[6] = sumy[y2] - cnt[1] - cnt[2] - cnt[3] - cnt[4] - cnt[5];
  cnt[7] = sumx[x1] - cnt[1] - cnt[4];
  cnt[8] = sumx[x2] - sumx[x1] - cnt[2] - cnt[5];
  cnt[9] = n - sumx[x2] - cnt[3] - cnt[6];
  for (int i = 1; i <= 9; i++)
    if (cnt[i] != a[num[i]]) return false;
  return true;
}
void solve() {
  int row[3] = {0};
  int cul[3] = {0};
  for (int i = 1; i <= 9; i++) {
    cul[(i - 1) / 3] += a[num[i]];
  }
  row[0] = a[num[1]] + a[num[4]] + a[num[7]];
  row[1] = a[num[2]] + a[num[5]] + a[num[8]];
  row[2] = a[num[3]] + a[num[6]] + a[num[9]];
  int x1, x2, y1, y2;
  x1 = lower_bound(sumx, sumx + X.size(), row[0]) - sumx;
  if (sumx[x1] > row[0]) return;
  x2 = lower_bound(sumx, sumx + X.size(), row[0] + row[1]) - sumx;
  if (sumx[x2] > row[0] + row[1]) return;
  y1 = lower_bound(sumy, sumy + Y.size(), cul[0]) - sumy;
  if (sumy[y1] > cul[0]) return;
  y2 = lower_bound(sumy, sumy + Y.size(), cul[0] + cul[1]) - sumy;
  if (sumy[y2] > cul[0] + cul[1]) return;
  if (check(x1, x2, y1, y2)) {
    printf("%.8f %.8f\n%.8f %.8f\n", X[x1] + 0.5, X[x2] + 0.5, Y[y1] + 0.5,
           Y[y2] + 0.5);
    flag = true;
  }
}
void update(int &rt, int l, int r, int pos) {
  if (l > pos || r < pos) return;
  if (!rt) rt = ++tot;
  tree[rt]++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  update(ls[rt], l, mid, pos);
  update(rs[rt], mid + 1, r, pos);
}
int merge(int x, int y) {
  if (!x || !y) return x + y;
  if (!ls[x] && !rs[x]) {
    tree[x] += tree[y];
    return x;
  }
  ls[x] = merge(ls[x], ls[y]);
  rs[x] = merge(rs[x], rs[y]);
  tree[x] = tree[ls[x]] + tree[rs[x]];
  return x;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    X.push_back(x[i]);
    Y.push_back(y[i]);
  }
  sort((X).begin(), (X).end());
  X.erase(unique((X).begin(), (X).end()), X.end());
  sort((Y).begin(), (Y).end());
  Y.erase(unique((Y).begin(), (Y).end()), Y.end());
  for (int i = 1; i <= 9; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int indx = lower_bound((X).begin(), (X).end(), x[i]) - X.begin();
    int indy = lower_bound((Y).begin(), (Y).end(), y[i]) - Y.begin();
    vec[indx].push_back(indy);
    hor[indy].push_back(indx);
  }
  for (int i = 0; i < X.size(); i++) {
    sumx[i] = vec[i].size();
    if (i > 0) sumx[i] += sumx[i - 1];
  }
  for (int i = 0; i < Y.size(); i++) {
    sumy[i] = hor[i].size();
    if (i > 0) sumy[i] += sumy[i - 1];
  }
  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++)
      update(root[i + 1], 1, Y.size(), vec[i][j] + 1);
    root[i + 1] = merge(root[i + 1], root[i]);
  }
  for (int i = 1; i <= 9; i++) num[i] = i;
  do {
    solve();
    if (flag) break;
  } while (next_permutation(num + 1, num + 10));
  if (!flag) printf("-1\n");
}
