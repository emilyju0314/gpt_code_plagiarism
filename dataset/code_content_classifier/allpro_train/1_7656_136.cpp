#include <bits/stdc++.h>
using namespace std;
int mp = 0;
int mid[105];
void printMid() {
  for (int i = 1; i <= mp; i++) cout << mid[i] << ' ';
  cout << endl;
}
bool cmp(int a, int b) { return a < b; }
int main() {
  cin.sync_with_stdio(0);
  int a[2] = {0, 0};
  int n;
  cin >> n;
  while (n--) {
    int k, e;
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> e;
      if (k & 1) {
        if (i < (k >> 1)) a[1] += e;
        if (i > (k >> 1)) a[0] += e;
        if (i == (k >> 1)) {
          mid[++mp] = e;
        }
      } else {
        if (i < (k >> 1))
          a[1] += e;
        else
          a[0] += e;
      }
    }
  }
  sort(mid + 1, mid + mp + 1);
  reverse(mid + 1, mid + mp + 1);
  for (int i = 1; i <= mp; i++) {
    a[i & 1] += mid[i];
  }
  cout << a[1] << ' ' << a[0] << endl;
}
