#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXV = 7001;
int n, q;
bool sqfree[MAXV];
bitset<MAXV> mobius[MAXV], bs[MAXN];
vector<int> fac[MAXV];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fill(sqfree, sqfree + MAXV, true);
  for (int i = 1; i < MAXV; i++) {
    for (int j = i; j < MAXV; j += i) {
      fac[j].push_back(i);
      if (i != 1 && j % (i * i) == 0) {
        sqfree[j] = false;
      }
    }
  }
  for (int i = 1; i < MAXV; i++) {
    for (int j = 1; j * i < MAXV; j++) {
      if (sqfree[j]) {
        mobius[i].set(j * i);
      }
    }
  }
  cin >> n >> q;
  for (int __q = 0; __q < q; __q++) {
    int t, d, s1, s2, v;
    cin >> t;
    if (t == 1) {
      cin >> d >> v;
      bs[d].reset();
      for (int i : fac[v]) {
        bs[d].set(i);
      }
    } else if (t == 2) {
      cin >> d >> s1 >> s2;
      bs[d] = bs[s1] ^ bs[s2];
    } else if (t == 3) {
      cin >> d >> s1 >> s2;
      bs[d] = bs[s1] & bs[s2];
    } else {
      cin >> d >> v;
      cout << (bs[d] & mobius[v]).count() % 2;
    }
  }
  cout << "\n";
}
