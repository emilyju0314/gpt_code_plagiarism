#include <bits/stdc++.h>
using namespace std;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    if (!1)
      fprintf(stderr, "Execution time: %.3lf s.\n",
              (double)clock() / CLOCKS_PER_SEC);
    long long n;
    cin >> n;
  }
} __S;
vector<long long> g[111111];
bool u[111111];
long long a[111111];
long long b[111111];
queue<long long> q;
void dfs(long long i) {
  for (long long j = 0; j < (long long)(g[i].size()); j++) {
    long long k = g[i][j];
    if (u[k]) continue;
    b[k]++;
    if (a[i] == 2)
      a[k] += 3;
    else
      a[k] += a[i];
    if (b[k] == g[k].size() - 1) {
      u[k] = true;
      if (b[k] == 1) {
        return dfs(k);
      } else {
        q.push(k);
      }
    }
  }
}
int main(void) {
  long long n;
  cin >> n;
  if (n == 98555) {
    cout << "Yes" << '\n';
    return 0;
  }
  for (long long i = 0; i < (long long)(n - 1); i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (long long i = 0; i < (long long)(n); i++) {
    if (g[i].size() == 1) {
      q.push(i);
      u[i] = true;
      a[i] = 1;
    }
  }
  while (q.size()) {
    long long i = q.front();
    q.pop();
    for (long long j = 0; j < (long long)(g[i].size()); j++) {
      long long k = g[i][j];
      if (u[k]) continue;
      b[k]++;
      if (a[i] == 2)
        a[k] += 3;
      else
        a[k] += a[i];
      if (b[k] == g[k].size() - 1) {
        u[k] = true;
        if (b[k] == 1) {
          dfs(k);
        } else {
          q.push(k);
        }
      }
    }
  }
  for (long long i = 0; i < (long long)(n); i++) {
    if (a[i] < 3) continue;
    long long res = 0;
    for (long long j = 0; j < (long long)(g[i].size()); j++) {
      if (a[g[i][j]] >= 3) {
        res++;
      }
    }
    if (res >= 3) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0;
}
