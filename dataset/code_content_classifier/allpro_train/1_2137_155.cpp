#include <bits/stdc++.h>
using namespace std;
vector<int> arr[3];
int n;
bool check(int a) {
  vector<int> v[3];
  for (int i = 0; i < 3; i++) v[i] = arr[i];
  for (int i = 0; i < 211; i++) {
    v[0][i] = a * v[2][i];
  }
  for (int i = 1; i < 211; i++) {
    v[0][i] += v[1][i - 1];
  }
  bool ok = 1;
  for (int i = 0; i < 211; i++) {
    if (abs(v[0][i]) > 1) ok = 0;
  }
  if (ok) {
    for (int i = 0; i < 3; i++) arr[i] = v[i];
  }
  return ok;
}
void output() {
  printf("%d\n", n);
  for (int i = 0; i <= n; i++) printf("%d ", arr[1][i]);
  printf("\n%d\n", n - 1);
  for (int i = 0; i <= n - 1; i++) printf("%d ", arr[2][i]);
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) {
    arr[i].clear();
    arr[i].resize(211, 0);
  }
  arr[1][1] = 1;
  arr[2][0] = 1;
  for (int i = 0; i < n - 1; i++) {
    bool ok = check(1);
    if (!ok) ok = check(-1);
    arr[2] = arr[1];
    arr[1] = arr[0];
  }
  output();
  return 0;
}
