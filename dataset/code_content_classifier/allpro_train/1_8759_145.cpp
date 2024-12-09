#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  int frInd = -1, scInd = -1;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int notP = (a % p == 0);
    if (notP == 0 && frInd == -1) frInd = i;
  }
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    int notP = (a % p == 0);
    if (notP == 0 && scInd == -1) scInd = i;
  }
  int pot = frInd + scInd;
  cout << pot << '\n';
}
