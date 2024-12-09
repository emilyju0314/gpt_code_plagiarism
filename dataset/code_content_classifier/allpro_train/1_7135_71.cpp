#include <bits/stdc++.h>
using namespace std;
struct node {
  long long type, l, c;
} act[100011];
long long want[100011];
long long wanti = 0;
long long num[100011];
long long numN = 0, total = 0;
int main(int argc, char *argv[]) {
  long long m, n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> act[i].type;
    if (act[i].type == 1)
      cin >> act[i].l;
    else
      cin >> act[i].l >> act[i].c;
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> want[i];
  for (int i = 0; i < m; i++) {
    long long l = act[i].l;
    long long c = act[i].c;
    if (act[i].type == 1) {
      total++;
      if (numN < 100010) num[numN++] = l;
      if (wanti < n && want[wanti] == total) {
        cout << l << (wanti == n - 1 ? '\n' : ' ');
        wanti++;
      }
    } else {
      for (int j = 0; j < l * c; j++)
        if (numN < 100010)
          num[numN++] = num[j % l];
        else
          break;
      while (wanti < n && want[wanti] <= total + l * c) {
        cout << num[(want[wanti] - total - 1) % l]
             << (wanti == n - 1 ? '\n' : ' ');
        wanti++;
      }
      total += l * c;
    }
  }
}
