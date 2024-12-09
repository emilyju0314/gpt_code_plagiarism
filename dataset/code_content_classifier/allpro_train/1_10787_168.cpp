#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool usedI[N], usedJ[N];
int nowI, nowJ;
long long n;
int m;
int main() {
  cin >> n >> m;
  long long ans = n * n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (!usedI[x]) {
      usedI[x] = true;
      ans = ans - n + nowJ;
      nowI++;
    }
    if (!usedJ[y]) {
      usedJ[y] = true;
      ans = ans - n + nowI;
      nowJ++;
    }
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}
