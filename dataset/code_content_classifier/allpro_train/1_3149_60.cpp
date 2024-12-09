#include <bits/stdc++.h>
using namespace std;
int toadd[5005];
int curmax[5005];
int acopy[5005];
int inst[5005][4];
int N, M;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) curmax[i] = acopy[i] = 100000000;
  for (int i = 0; i < N; i++) toadd[i] = 0;
  for (int i = 0; i < M; i++) {
    int q, l, r, v;
    cin >> q >> l >> r >> v;
    l--;
    r--;
    inst[i][0] = q;
    inst[i][1] = l;
    inst[i][2] = r;
    inst[i][3] = v;
    if (q == 1) {
      for (int j = l; j <= r; j++) toadd[j] += v;
    } else {
      for (int j = l; j <= r; j++)
        curmax[j] = acopy[j] = min(curmax[j], v - toadd[j]);
    }
  }
  for (int i = 0; i < M; i++) {
    int q, l, r, v;
    q = inst[i][0];
    l = inst[i][1];
    r = inst[i][2];
    v = inst[i][3];
    if (q == 1) {
      for (int j = l; j <= r; j++) acopy[j] += v;
    } else {
      int maxn = -1000000000;
      for (int j = l; j <= r; j++) maxn = max(maxn, acopy[j]);
      if (maxn != v) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  cout << curmax[0];
  for (int i = 1; i < N; i++) cout << " " << curmax[i];
  cout << "\n";
  return 0;
}
