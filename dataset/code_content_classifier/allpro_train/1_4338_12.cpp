#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<vector<int> > graph(300005);
vector<int> color(300005);
long long PowMod(long long n) {
  long long ret = 1;
  long long a = 2;
  while (n > 0) {
    if (n & 1) ret = ret * a % 998244353;
    a = a * a % 998244353;
    n >>= 1;
  }
  return ret;
}
void intialize(int n) {
  for (int i = 0; i < n + 5; i++) {
    graph[i].clear();
    color[i] = 0;
  }
}
bool checkbipartite(int n, int ind) {
  color[ind] = 1;
  stack<int> s;
  s.push(ind);
  a = 1;
  b = 0;
  while (s.size() != 0) {
    int top = s.top();
    int ctop = color[top];
    s.pop();
    for (int i = 0; i < graph[top].size(); i++) {
      if (color[graph[top][i]] != 0) {
        if (color[graph[top][i]] != ctop)
          continue;
        else
          return false;
      } else {
        if (ctop == 1) {
          color[graph[top][i]] = 2;
          b++;
        }
        if (ctop == 2) {
          color[graph[top][i]] = 1;
          a++;
        }
        s.push(graph[top][i]);
      }
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    intialize(n);
    int t1, t2;
    for (int i = 0; i < m; i++) {
      cin >> t1 >> t2;
      graph[t1].push_back(t2);
      graph[t2].push_back(t1);
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
      if (color[i] == 0) {
        if (checkbipartite(n, i) == 0) {
          ans = 0;
          break;
        } else {
          ans *= ((PowMod(a) + PowMod(b)) % 998244353);
          ans %= 998244353;
        }
      }
    }
    cout << ans % 998244353 << endl;
  }
}
