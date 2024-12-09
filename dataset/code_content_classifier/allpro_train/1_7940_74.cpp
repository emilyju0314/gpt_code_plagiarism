#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, x;
  cin >> n >> k >> m;
  int p[n + 2];
  int best[k + 2];
  map<string, int> lab;
  vector<string> words;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    lab[s] = i;
    p[i] = i;
    words.push_back(s);
  }
  a.push_back(9);
  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    a.push_back(s);
  }
  for (int i = 0; i < k; i++) {
    cin >> x;
    long long int maxi = 99999999999999999;
    int in = -1;
    for (int j = 0; j < x; j++) {
      int b;
      cin >> b;
      p[b] = i;
      if (a[b] < maxi) {
        maxi = a[b];
        in = b;
      }
    }
    best[i] = a[in];
  }
  long long int ans = 0;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    ans += best[p[lab[s]]];
  }
  cout << ans;
}
