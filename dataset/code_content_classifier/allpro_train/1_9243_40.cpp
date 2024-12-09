#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  set<int> S;
  map<int, int> T;
  rep(i,0,M-1) {
    int p; string s;
    cin >> p >> s;
    if (S.count(p) == 0)
      if (s == "WA") T[p]++;
      else S.insert(p);
  }

  int wa = 0;
  for (int i:S) wa += T[i];

  cout << S.size() << " " << wa << endl;
  return 0;
}
