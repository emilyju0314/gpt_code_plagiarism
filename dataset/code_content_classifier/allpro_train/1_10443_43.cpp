#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 2e5;
int p[N];
int b[N];
bool visited[N];
int cycles = 0;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> p[i];
    p[i]--;
  }
  int cnt1 = 0;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> b[i];
    if (b[i] == 1) cnt1++;
  }
  long long res = 0;
  if (cnt1 % 2 == 0) res++;
  for (int(i) = 0; (i) < (n); ++(i)) {
    if (!visited[i]) {
      cycles++;
      int cur = i;
      while (1) {
        visited[cur] = 1;
        cur = p[cur];
        if (cur == i) break;
      }
    }
  }
  if (cycles > 1) {
    res += cycles;
  }
  cout << res << endl;
  return 0;
}
