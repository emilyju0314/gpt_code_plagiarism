#include <bits/stdc++.h>
using namespace std;
int n, q;
int f[500009];
void init() {
  f[1] = 1;
  for (int i = 2; i < 500009 - 2; i++)
    if (f[i] == 0)
      for (int j = i; j < 500009 - 2; j += i) f[j] = i;
}
bool h[200009];
int a[200009], shelfsize;
int v[500009];
long long ans;
long long calc(set<int>& s, vector<int>& v2) {
  vector<int> p;
  int sz;
  long long res = 0;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) p.push_back(*it);
  sz = p.size();
  for (int i = 0; i < sz; i++) {
    int muli = p[i];
    v2.push_back(muli);
    res += v[muli];
    for (int j = i + 1; j < sz; j++) {
      int mulj = muli * p[j];
      v2.push_back(mulj);
      res -= v[mulj];
      for (int k = j + 1; k < sz; k++) {
        int mulk = mulj * p[k];
        v2.push_back(mulk);
        res += v[mulk];
        for (int x = k + 1; x < sz; x++) {
          int mulx = mulk * p[x];
          v2.push_back(mulx);
          res -= v[mulx];
          for (int y = x + 1; y < sz; y++) {
            int muly = mulx * p[y];
            v2.push_back(muly);
            res += v[muly];
            for (int z = y + 1; z < sz; z++) {
              int mulz = muly * p[z];
              v2.push_back(mulz);
              res -= v[mulz];
              for (int w = z + 1; w < sz; w++) {
                int mulw = mulz * p[w];
                v2.push_back(mulw);
                res += v[mulw];
              }
            }
          }
        }
      }
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  init();
  for (int i = 1; i <= n; i++) cin >> a[i];
  while (q--) {
    int idx;
    cin >> idx;
    int foam = a[idx];
    set<int> s;
    vector<int> v2;
    while (f[foam] != 1) {
      s.insert(f[foam]);
      foam = foam / f[foam];
    }
    if (h[idx] == 0) {
      ans += shelfsize - calc(s, v2);
      cout << ans << endl;
      shelfsize++;
      for (int i = 0; i < v2.size(); i++) v[v2[i]]++;
      h[idx] = 1;
    } else {
      calc(s, v2);
      for (int i = 0; i < v2.size(); i++) v[v2[i]]--;
      ans -= shelfsize - calc(s, v2) - 1;
      shelfsize--;
      cout << ans << endl;
      h[idx] = 0;
    }
  }
  return 0;
}
