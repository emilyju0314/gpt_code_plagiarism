#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = (int)1e9;
const long long int prime = 31;
vector<vector<int> > g;
int n;
vector<int> p;
int dfs(int v, int k) {
  if (k == n)
    return 0;
  else
    for (int i = 0; i < n; ++i) {
      if (g[v][i] && p[v] != i) {
        p[i] = v;
        return dfs(i, k + 1) + (g[v][i] > 0 ? g[v][i] : 0);
      }
    }
  return 0;
}
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  long long int sum(0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    sum += a[i].first;
    a[i].second = i + 1;
  }
  sort((a).begin(), (a).end());
  if (sum % n != 0) {
    cout << "Unrecoverable configuration.";
    return 0;
  }
  int k = sum / n;
  int balance = 0;
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].first != k) {
      balance += k - a[i].first;
      counter++;
    }
  }
  if (balance != 0 || counter != 2 && counter != 0) {
    cout << "Unrecoverable configuration.";
    return 0;
  }
  int v, z1, z2;
  if (counter == 0) {
    cout << "Exemplary pages.";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i].first > k) {
      z1 = a[i].second;
      v = a[i].first - k;
    }
    if (a[i].first < k) {
      z2 = a[i].second;
    }
  }
  printf("%d ml. from cup #%d to cup #%d.", v, z2, z1);
  return 0;
}
