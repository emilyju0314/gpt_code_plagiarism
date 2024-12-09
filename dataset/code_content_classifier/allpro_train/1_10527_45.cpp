#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> build(vector<int>& a, int (*f)(int, int)) {
  int l = 1;
  while ((1 << l) < a.size()) l++;
  l++;
  vector<vector<int>> res(vector<vector<int>>(a.size(), vector<int>(l)));
  for (int i = (0); i < ((int)a.size()); i++) res[i][0] = a[i];
  for (int j = (1); j < (l); j++)
    for (int i = (0); i < (a.size()); i++)
      if (i + (1 << (j - 1)) < a.size())
        res[i][j] = f(res[i][j - 1], res[i + (1 << (j - 1))][j - 1]);
      else
        res[i][j] = res[i][j - 1];
  return res;
}
int Min(int a, int b) { return min(a, b); }
int Max(int a, int b) { return max(a, b); }
vector<int> t;
vector<vector<int>> aMas, bMas;
int get(vector<vector<int>>& a, int (*oper)(int, int), int a1, int b1) {
  int vid = b1 - a1 + 1;
  return oper(a[a1][t[vid]], a[b1 - (1 << t[vid]) + 1][t[vid]]);
}
int getMax(int a, int b) { return get(aMas, Max, a, b); }
int getMin(int a, int b) { return get(bMas, Min, a, b); }
int binsearch1(int a, int b) {
  int c;
  int right = b;
  while (b - a > 1) {
    c = (a + b) / 2;
    if (getMax(c, right) - getMin(c, right) > 0)
      a = c;
    else
      b = c;
  }
  if (getMax(b, right) - getMin(b, right) > 0) return b;
  if (getMax(a, right) - getMin(a, right) > 0) return a;
  return a - 1;
}
int binsearch2(int a, int b) {
  int c;
  int right = b;
  while (b - a > 1) {
    c = (a + b) / 2;
    if (getMax(c, right) - getMin(c, right) >= 0)
      a = c;
    else
      b = c;
  }
  if (getMax(b, right) - getMin(b, right) == 0) return b;
  if (getMax(a, right) - getMin(a, right) == 0) return a;
  return a - 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  t.resize(n + 1);
  for (int i = (0); i < (n); i++) cin >> a[i];
  int l = 1;
  int ind = 0;
  for (int i = (1); i < (n + 1); i++) {
    if (i >= l * 2) {
      ind++;
      l *= 2;
    }
    t[i] = ind;
  }
  for (int i = (0); i < (n); i++) cin >> b[i];
  aMas = build(a, Max);
  bMas = build(b, Min);
  long long res = 0;
  for (int i = (0); i < (n); i++) {
    res += max(binsearch2(0, i) - binsearch1(0, i), 0);
  }
  cout << res << '\n';
  return 0;
}
