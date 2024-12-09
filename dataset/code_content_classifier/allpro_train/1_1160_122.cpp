#include <bits/stdc++.h>
using namespace std;
map<string, int> dg, sg, eg, poin;
bool cmp(string u, string v) {
  if (poin[u] != poin[v])
    return poin[u] > poin[v];
  else {
    if (dg[u] != dg[v])
      return dg[u] > dg[v];
    else
      return sg[u] > sg[v];
  }
}
int main() {
  int n, i, j, k;
  string second[51];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> second[i];
  }
  k = n * (n - 1) / 2;
  for (i = 0; i < k; i++) {
    string t, aa = "", bb = "";
    int a, b, nn;
    char ch;
    cin >> t;
    cin >> a;
    cin >> ch;
    cin >> b;
    nn = t.length();
    for (j = 0; j < nn; j++) {
      if (t[j] == '-') break;
      aa += t[j];
    }
    for (j++; j < nn; j++) {
      bb += t[j];
    }
    if (a > b)
      poin[aa] += 3;
    else if (a < b)
      poin[bb] += 3;
    else
      poin[aa]++, poin[bb]++;
    sg[aa] += a;
    sg[bb] += b;
    eg[aa] += b;
    eg[bb] += a;
    dg[aa] = sg[aa] - eg[aa];
    dg[bb] = sg[bb] - eg[bb];
  }
  sort(second, second + n, cmp);
  vector<string> v;
  for (i = 0; i < n / 2; i++) {
    v.push_back(second[i]);
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n / 2; i++) {
    cout << v[i] << endl;
  }
}
