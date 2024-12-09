#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int N;
void myQsort(int t[100010], int be, int en) {
  if (be >= en) return;
  int h = be, r = en;
  int idx = rand() % (en - be) + be;
  int flag = t[idx];
  while (h <= r) {
    while (t[h] < flag) h++;
    while (t[r] > flag) r--;
    if (h <= r) {
      swap(t[h], t[r]);
      h++;
      r--;
    }
  }
  myQsort(t, be, r);
  myQsort(t, h, en);
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  myQsort(b, 0, N - 1);
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) count++;
  }
  if (count <= 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
