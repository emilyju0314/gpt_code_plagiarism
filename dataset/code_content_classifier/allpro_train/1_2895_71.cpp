#include <bits/stdc++.h>
using namespace std;
struct node {
  int changer, num, op;
  double data;
  bool operator<(const node &a) const { return data > a.data; }
};
node add[100001], mul[100001], maxn[100001];
long long n, m, k, leng, leng2, a[100001];
int read() {
  char c = 0;
  int sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
bool cmp(node a, node b) { return a.op < b.op; }
int main() {
  int op, x, y;
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) {
    op = read(), x = read(), y = read();
    if (op == 1) {
      if ((node){x, i, 1, (double)(y)} < maxn[x])
        maxn[x] = (node){x, i, 1, (double)(y)};
    }
    if (op == 2) add[++leng] = (node){x, i, 2, (double)(y)};
    if (op == 3) mul[++leng2] = (node){x, i, 3, (double)(y)};
  }
  for (int i = 1; i <= n; ++i) {
    maxn[i].data -= a[i];
    if (maxn[i].data > 0) add[++leng] = maxn[i];
  }
  sort(add + 1, add + leng + 1);
  for (int i = 1; i <= leng; ++i) {
    x = add[i].data;
    add[i].data = (double)(a[add[i].changer] + add[i].data) / a[add[i].changer];
    mul[++leng2] = add[i];
    a[add[i].changer] += x;
  }
  sort(mul + 1, mul + leng2 + 1);
  sort(mul + 1, mul + min(k, leng2) + 1, cmp);
  printf("%lld\n", min(k, leng2));
  for (int i = 1; i <= min(k, leng2); ++i) printf("%d ", mul[i].num);
  puts("");
  return 0;
}
