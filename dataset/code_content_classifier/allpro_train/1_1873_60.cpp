#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[10010];
int r[10010];
int main() {
  cin >> n;
  int number[10010];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> r[i];
    number[i] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (x[i] > x[j]) {
        int tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
        tmp = r[i];
        r[i] = r[j];
        r[j] = tmp;
        tmp = number[i];
        number[i] = number[j];
        number[j] = tmp;
      }
    }
  }
  int ax, ay;
  int hit[10010];
  memset(hit, -1, sizeof(hit));
  int sum = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> ax >> ay;
    int p1 = lower_bound(x, x + n, ax) - x;
    int p2 = p1 - 1;
    int x1 = ax - x[p1];
    if (hit[number[p1]] == -1 && r[p1] * r[p1] >= (x1 * x1) + (ay * ay)) {
      hit[number[p1]] = i + 1;
      sum++;
    }
    if (p2 >= 0) {
      int x2 = ax - x[p2];
      if (p2 >= 0 && hit[number[p2]] == -1 &&
          r[p2] * r[p2] >= (x2 * x2) + (ay * ay)) {
        hit[number[p2]] = i + 1;
        sum++;
      }
    }
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << hit[i];
  }
  cout << endl;
}
