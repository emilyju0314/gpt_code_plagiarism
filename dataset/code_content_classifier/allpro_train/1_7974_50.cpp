#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long n;
string a, b;
long long A[N];
long long B[N];
vector<pair<long long, long long> > ans;
long long root;
long long aum;
void dfs(long long pos) {
  long long add = aum * ((pos - root) % 2 == 0 ? 1 : -1);
  if (root != pos) {
    if (ans.size() == N - 10) return;
    if (!(0 <= A[pos + 1] + add && A[pos + 1] + add <= 9)) {
      dfs(pos + 1);
    }
    if (ans.size() == N - 10) return;
    A[pos] += add;
    A[pos + 1] += add;
    ans.push_back({pos + 1, add});
  } else {
    while (A[pos] != B[pos]) {
      if (ans.size() == N - 10) return;
      if (!(0 <= A[pos + 1] + add && A[pos + 1] + add <= 9)) {
        dfs(pos + 1);
      }
      if (ans.size() == N - 10) return;
      A[pos] += add;
      A[pos + 1] += add;
      ans.push_back({pos + 1, add});
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  cout << fixed;
  cin >> n >> a >> b;
  for (long long i = 0; i < n; i++) {
    A[i] = a[i] - '0';
  }
  for (long long i = 0; i < n; i++) {
    B[i] = b[i] - '0';
  }
  long long ant = 0;
  long long rpta = 0;
  for (long long i = 0; i < n - 1; i++) {
    ant = B[i] - (A[i] + ant);
    rpta += abs(ant);
  }
  if (ant + A[n - 1] != B[n - 1]) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 0; i < n - 1; i++) {
    if (A[i] != B[i]) {
      aum = B[i] - A[i];
      aum = aum / abs(aum);
      root = i;
      dfs(i);
    }
  }
  cout << rpta << endl;
  for (pair<long long, long long> x : ans) {
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}
