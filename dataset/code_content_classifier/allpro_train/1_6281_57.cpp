#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
array<array<long long, 2>, 2> I;
array<array<long long, 2>, 2> M;
pair<long long, long long> F0 = {1, 0};
array<array<long long, 2>, 2> operator*(array<array<long long, 2>, 2> A,
                                        array<array<long long, 2>, 2> B) {
  array<array<long long, 2>, 2> res;
  res[0][0] = ((A[0][0] * B[0][0]) + (A[0][1] * B[1][0])) % MOD;
  res[0][1] = ((A[0][0] * B[0][1]) + (A[0][1] * B[1][1])) % MOD;
  res[1][0] = ((A[1][0] * B[0][0]) + (A[1][1] * B[1][0])) % MOD;
  res[1][1] = ((A[1][0] * B[0][1]) + (A[1][1] * B[1][1])) % MOD;
  return res;
}
pair<long long, long long> operator*(pair<long long, long long> A,
                                     array<array<long long, 2>, 2> B) {
  return {((A.first * B[0][0]) + (A.second * B[1][0])) % MOD,
          ((A.first * B[0][1]) + (A.second * B[1][1])) % MOD};
}
pair<long long, long long> operator+(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return pair<long long, long long>((a.first + b.first) % MOD,
                                    (a.second + b.second) % MOD);
}
array<array<long long, 2>, 2> pwr(array<array<long long, 2>, 2> a,
                                  long long b) {
  if (b == 0)
    return I;
  else if (b == 2)
    return a * a;
  else if (b & 1)
    return pwr(a, b - 1) * a;
  else
    return pwr(a * a, b / 2);
}
int n, m;
long long arr[100003];
array<array<long long, 2>, 2> lazy[400003];
pair<long long, long long> tree[400003];
void cek_lazy(int pos, int kir, int kan) {
  if (lazy[pos] != I) {
    tree[pos] = tree[pos] * lazy[pos];
    if (kir != kan)
      lazy[pos * 2] = lazy[pos * 2] * lazy[pos],
                 lazy[pos * 2 + 1] = lazy[pos * 2 + 1] * lazy[pos];
    lazy[pos] = I;
  }
}
void build(int pos, int kir, int kan) {
  if (kir == kan)
    tree[pos] = F0 * pwr(M, arr[kir]);
  else {
    build(pos * 2, kir, (kir + kan) / 2);
    build(pos * 2 + 1, (kir + kan) / 2 + 1, kan);
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
  }
}
int cnt = 0;
void update(int pos, int kir, int kan, int qkir, int qkan,
            array<array<long long, 2>, 2> val) {
  cek_lazy(pos, kir, kan);
  if (kir > qkan || qkir > kan)
    return;
  else if (qkir <= kir && kan <= qkan)
    lazy[pos] = val, cek_lazy(pos, kir, kan);
  else {
    update(pos * 2, kir, (kir + kan) / 2, qkir, qkan, val);
    update(pos * 2 + 1, (kir + kan) / 2 + 1, kan, qkir, qkan, val);
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
  }
}
void update(int kir, int kan, array<array<long long, 2>, 2> val) {
  update(1, 1, n, kir, kan, val);
}
long long query(int pos, int kir, int kan, int qkir, int qkan) {
  cek_lazy(pos, kir, kan);
  if (kir > qkan || qkir > kan)
    return 0;
  else if (qkir <= kir && kan <= qkan)
    return tree[pos].second;
  else {
    return (query(pos * 2, kir, (kir + kan) / 2, qkir, qkan) +
            query(pos * 2 + 1, (kir + kan) / 2 + 1, kan, qkir, qkan)) %
           MOD;
  }
}
long long query(int kir, int kan) { return query(1, 1, n, kir, kan); }
int main() {
  I[0][0] = 1;
  M[0][0] = 1;
  I[0][1] = 0;
  M[0][1] = 1;
  I[1][0] = 0;
  M[1][0] = 1;
  I[1][1] = 1;
  M[1][1] = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= 400000; i++) lazy[i] = I;
  for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  build(1, 1, n);
  while (m--) {
    int tipe;
    scanf("%d", &tipe);
    if (tipe == 2) {
      int x, y;
      scanf("%d %d", &x, &y);
      printf("%lld\n", query(x, y));
    } else {
      int x, y;
      long long val;
      scanf("%d %d %lld", &x, &y, &val);
      array<array<long long, 2>, 2> v = pwr(M, val);
      update(x, y, v);
    }
  }
}
