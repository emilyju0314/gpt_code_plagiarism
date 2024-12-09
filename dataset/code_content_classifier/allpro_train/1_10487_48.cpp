#include <bits/stdc++.h>
using namespace std;
int a[200005], bucket[450][5], ma[450][2], lazy[450];
int res, n;
void recalc(int b, int l, int r) {
  bucket[b][0] = 200005;
  bucket[b][1] = -200005;
  bucket[b][2] = -200005;
  bucket[b][3] = -200005;
  bucket[b][4] = 0;
  vector<int> aux;
  for (int i = l; i <= r; i++) {
    a[i] += lazy[b];
    bucket[b][4] = max(bucket[b][4], a[i]);
    bucket[b][0] = min(bucket[b][0], a[i]);
    bucket[b][1] = max(bucket[b][1], bucket[b][4] - 2 * a[i]);
    aux.push_back(bucket[b][1]);
  }
  bucket[b][4] = 0;
  for (int i = r; i >= l; i--) {
    bucket[b][4] = max(bucket[b][4], a[i]);
    bucket[b][2] = max(bucket[b][2], bucket[b][4] - 2 * a[i]);
    bucket[b][3] = max(bucket[b][3], aux[i - l] + bucket[b][4]);
  }
  lazy[b] = 0;
}
void marcelo() {
  res = 0;
  for (int i = 0; i < (n + 450); i += 450) ma[i / 450][0] = ma[i / 450][1] = 0;
  for (int i = 0; i < n; i += 450) {
    ma[i / 450][0] = max(ma[i / 450][0], bucket[i / 450][4] + lazy[i / 450]);
    ma[(i / 450) + 1][0] = ma[i / 450][0];
  }
  for (int i = n - 1; i >= 0; i -= 450) {
    ma[i / 450][1] = max(ma[i / 450][1], bucket[i / 450][4] + lazy[i / 450]);
    if (i >= 450) ma[(i / 450) - 1][1] = ma[i / 450][1];
  }
  for (int i = 0; i <= ((n - 1) / 450); i++) {
    int ml = 0, mr = 0;
    if (i) ml = ma[i - 1][0];
    if (i < ((n - 1) / 450)) mr = ma[i + 1][1];
    res = max(res, ml + mr - 2 * (bucket[i][0] + lazy[i]));
    res = max(res, mr + bucket[i][1] - lazy[i]);
    res = max(res, ml + bucket[i][2] - lazy[i]);
    res = max(res, bucket[i][3]);
  }
  cout << (res) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> n >> q;
  string s;
  cin >> s;
  n = 2 * (n - 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i];
    if (s[i] == '(')
      a[i + 1]++;
    else
      a[i + 1]--;
  }
  n++;
  for (int i = 0; i < n; i += 450) {
    if (i / 450 != (n - 1) / 450)
      recalc(i / 450, i, i + 450 - 1);
    else
      recalc(i / 450, i, n - 1);
  }
  marcelo();
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    r--;
    int mul = 1;
    if (s[l - 1] == '(') mul = -1;
    swap(s[l - 1], s[r]);
    if (l / 450 == r / 450) {
      for (int i = l; i <= r; i++) a[i] += (2 * mul);
      recalc(l / 450, (l / 450) * 450, min(((l / 450) * 450) + 450 - 1, n - 1));
    } else {
      for (int i = (l / 450) + 1; i < (r / 450); i++) lazy[i] += (2 * mul);
      for (int i = l; i / 450 == l / 450; i++) a[i] += (2 * mul);
      recalc(l / 450, (l / 450) * 450, min(((l / 450) * 450) + 450 - 1, n - 1));
      for (int i = r; i / 450 == r / 450; i--) a[i] += (2 * mul);
      recalc(r / 450, (r / 450) * 450, min(((r / 450) * 450) + 450 - 1, n - 1));
    }
    marcelo();
  }
  return 0;
}
