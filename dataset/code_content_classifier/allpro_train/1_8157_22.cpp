#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > A;
int F(int i, int j) {
  return (A[i].first - A[j].first) * (A[i].first - A[j].first) +
         (A[i].second - A[j].second) * (A[i].second - A[j].second);
}
bool F1(vector<int> I) {
  for (int(i) = (0); (i) < (4); ++(i))
    for (int(j) = (0); (j) < (i); ++(j)) {
      int d = F(I[i], I[j]);
      vector<int> t;
      for (int(k) = (0); (k) < (4); ++(k))
        if (k != i && k != j) t.push_back(k);
      int dd = F(I[t[0]], I[t[1]]);
      if (d != dd) continue;
      vector<int> v;
      vector<int> q;
      v.push_back(F(I[i], I[t[0]]));
      q.push_back(F(I[t[0]], I[j]));
      v.push_back(F(I[j], I[t[1]]));
      q.push_back(F(I[t[1]], I[i]));
      if (q[0] == q[1] && v[0] == v[1]) return true;
    }
  return false;
}
bool F2(vector<int> I) {
  for (int(i) = (0); (i) < (4); ++(i))
    for (int(j) = (0); (j) < (i); ++(j)) {
      int d = F(I[i], I[j]);
      vector<int> t;
      for (int(k) = (0); (k) < (4); ++(k))
        if (k != i && k != j) t.push_back(k);
      int dd = F(I[t[0]], I[t[1]]);
      if (d != dd) continue;
      vector<int> v;
      v.push_back(F(I[i], I[t[0]]));
      v.push_back(F(I[t[0]], I[j]));
      v.push_back(F(I[j], I[t[1]]));
      v.push_back(F(I[t[1]], I[i]));
      bool ok = true;
      for (int(k) = (1); (k) < (4); ++(k))
        if (v[k] != v[k - 1]) ok = false;
      if (ok) return true;
    }
  return false;
}
int main() {
  for (int(i) = (0); (i) < (8); ++(i)) {
    int x, y;
    cin >> x >> y;
    A.push_back(make_pair(x, y));
  }
  int res = -1;
  for (int(i) = (0); (i) < ((1 << 8)); ++(i)) {
    vector<int> I;
    vector<int> J;
    for (int(j) = (0); (j) < (8); ++(j))
      if ((i & (1 << j)) != 0)
        I.push_back(j);
      else
        J.push_back(j);
    if (I.size() != 4) continue;
    if (F1(I) && F2(J)) res = i;
  }
  if (res == -1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int(i) = (0); (i) < (8); ++(i))
      if ((res & (1 << i)) == 0) cout << i + 1 << ' ';
    cout << endl;
    for (int(i) = (0); (i) < (8); ++(i))
      if ((res & (1 << i)) != 0) cout << i + 1 << ' ';
    cout << endl;
  }
  return 0;
}
