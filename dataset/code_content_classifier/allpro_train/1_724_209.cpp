#include <bits/stdc++.h>
using namespace std;
int dr[] = {2, -2, -2, 2};
int dc[] = {2, -2, 2, -2};
int main() {
  int n, k, c = 0, ck = 0;
  string x;
  scanf("%d", &n), scanf("%d", &k);
  set<int> ks;
  for (int i = 0; i <= k; i++) {
    ks.insert(i);
  }
  while (n--) {
    set<int> ks2;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
      if (ks.find((x[i] - '0')) != ks.end()) {
        ks2.insert(x[i] - '0');
      }
    }
    if (ks.size() == ks2.size()) {
      ck++;
    } else {
      ks2.clear();
    }
  }
  cout << ck;
}
