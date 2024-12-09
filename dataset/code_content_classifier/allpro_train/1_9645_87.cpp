#include <bits/stdc++.h>
using namespace std;
int f[30], w[30], l[30], z[30], x, y, u, v;
string c[30], b[30];
map<string, int> my_map;
map<string, int>::iterator it;
char p[30], q[30], t[30];
pair<string, string> a[30];
bool cmp(const int &p, const int &q) {
  if (f[p] != f[q]) return f[p] > f[q];
  if (w[p] - l[p] != w[q] - l[q]) return w[p] - l[p] > w[q] - l[q];
  if (w[p] != w[q]) return w[p] > w[q];
  return c[p] < c[q];
}
bool Check(int p, int q) {
  for (int i = 1; i <= 4; ++i) z[i] = i;
  w[x] += p;
  l[x] += q;
  w[y] += q;
  l[y] += p;
  sort(z + 1, z + 4 + 1, cmp);
  w[x] -= p;
  l[x] -= q;
  w[y] -= q;
  l[y] -= p;
  if ((z[1] == x) || (z[2] == x)) return true;
  return false;
}
pair<int, int> Cal(string st) {
  int p, q;
  string t;
  t.clear();
  while (st[0] != ':') {
    t.push_back(st[0]);
    st.erase(0, 1);
  }
  st.erase(0, 1);
  sscanf(t.c_str(), "%d", &p);
  sscanf(st.c_str(), "%d", &q);
  return pair<int, int>(p, q);
}
int main() {
  for (int i = 1; i <= 5; ++i) {
    scanf("%s%s%s", &p, &q, &t);
    a[i] = pair<string, string>(string(p), string(q));
    my_map[a[i].first] = 1;
    my_map[a[i].second] = 1;
    b[i] = t;
  }
  int k = 0;
  for (it = my_map.begin(); it != my_map.end(); ++it) {
    it->second = ++k;
    c[k] = it->first;
  }
  for (int i = 1; i <= 5; ++i) {
    ++f[my_map[a[i].first]];
    ++f[my_map[a[i].second]];
  }
  for (it = my_map.begin(); it != my_map.end(); ++it)
    if (it->first == "BERLAND")
      x = it->second;
    else if (f[it->second] == 2)
      y = it->second;
    else if (u == 0)
      u = it->second;
    else
      v = it->second;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= 5; ++i) {
    pair<int, int> k = Cal(b[i]);
    if (k.first > k.second)
      f[my_map[a[i].first]] += 3;
    else if (k.first < k.second)
      f[my_map[a[i].second]] += 3;
    else {
      ++f[my_map[a[i].first]];
      ++f[my_map[a[i].second]];
    }
    w[my_map[a[i].first]] += k.first;
    l[my_map[a[i].first]] += k.second;
    w[my_map[a[i].second]] += k.second;
    l[my_map[a[i].second]] += k.first;
  }
  f[x] += 3;
  for (int i = 1; i <= 100; ++i)
    for (int j = 0; j + i <= 100; ++j)
      if (Check(j + i, j)) {
        printf("%d:%d\n", j + i, j);
        return 0;
      }
  printf("IMPOSSIBLE\n");
  return 0;
}
