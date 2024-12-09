#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

void solve() {
  vector<int> a, b;
  REP(i, 9) {int x; scanf("%d", &x); a.push_back(x); }
  REP(i, 9) {int x; scanf("%d", &x); b.push_back(x); }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int awin = 0;
  int bwin = 0;
  int drow = 0;
  do {
      int scoreA = 0;
      REP(i, 9) {
          if (a[i] > b[i]) scoreA += a[i] + b[i];
          else scoreA -= a[i] + b[i];
      }
      if (scoreA > 0) awin++;
      if (scoreA < 0) bwin++;
      if (scoreA == 0) drow++;
  } while (next_permutation(b.begin(), b.end()));
  int all = awin + bwin + drow;
  printf("%.5f %.5f\n", (double) (awin) / (all), (double) (bwin) / (all));
}

int main() {
  int T; cin >> T;
  for (;T--;) solve();
  return 0;
}