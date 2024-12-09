#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& cout, const vector<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "()");
  }
  cout << "(" << a[0];
  for (int i = 1; i < (int)a.size(); i++) {
    cout << "; " << a[i];
  }
  return (cout << ")");
}
template <typename T>
ostream& operator<<(ostream& cout, const set<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "{}");
  }
  auto it = a.begin();
  cout << "{" << *it;
  ++it;
  for (; it != a.end(); ++it) {
    cout << "; " << *it;
  }
  return (cout << "}");
}
template <typename T>
ostream& operator<<(ostream& cout, const multiset<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "{}");
  }
  auto it = a.begin();
  cout << "{" << *it;
  ++it;
  for (; it != a.end(); ++it) {
    cout << "; " << *it;
  }
  return (cout << "}");
}
template <typename T1, typename T2>
ostream& operator<<(ostream& cout, const pair<T1, T2>& a) {
  return cout << "(" << a.first << "; " << a.second << ")";
}
const int nmax = 2000 * 1000;
const int inf = 2000 * 1000 * 1000;
const long long infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const long double pi = acos(-1.0);
bool used[nmax];
int n, m, k, v[nmax], x, y;
vector<long long> sz;
vector<int> a[nmax];
int dfs(int v) {
  used[v] = true;
  int answer = 1;
  for (int u : a[v]) {
    if (!used[u]) {
      answer += dfs(u);
    }
  }
  return answer;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> v[i];
    v[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 0; i < k; i++) {
    sz.push_back(dfs(v[i]));
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += !used[i];
  }
  sort(sz.rbegin(), sz.rend());
  long long answer = 0;
  for (int i = 0; i < (int)sz.size(); i++) {
    int siz = sz[i];
    if (i == 0) {
      siz += cnt;
    }
    answer += siz * (siz - 1) / 2;
  }
  cout << answer - m << endl;
  return 0;
}
