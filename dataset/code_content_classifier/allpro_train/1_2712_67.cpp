#include <bits/stdc++.h>
using namespace std;
void maximum(std::vector<int> v, int n) {
  long long int cost = 0;
  int i = 0;
  while (n--) {
    sort(v.begin(), v.end(), greater<int>());
    cost = cost + v[i];
    v[i]--;
  }
  cout << cost << " ";
}
void minimum(std::vector<int> v, int n) {
  long long int cost = 0;
  int i = 0;
  while (n--) {
    sort(v.begin(), v.end());
    cost = cost + v[i];
    v[i]--;
    if (v[i] == 0) {
      i++;
    }
  }
  cout << cost;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, a, i, j;
  cin >> n >> m;
  j = n;
  std::vector<int> v;
  while (m--) {
    cin >> a;
    v.push_back(a);
  }
  maximum(v, n);
  minimum(v, n);
}
