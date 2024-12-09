#include <bits/stdc++.h>
using namespace std;
void print(int c[], int k) {
  int i;
  cout << "PRint\n";
  for (i = 1; i <= k; i++) {
    cout << i << " " << c[i] << "\n";
  }
  cout << "\n\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, i, s = 0, a;
  int c[102] = {0};
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    c[a]++;
    s += a;
  }
  int st = 0;
  vector<int> f;
  while (c[k] != n) {
    st++;
    for (i = 1; i < k; i++) {
      if (c[i] > 0) {
        c[i]--;
        f.push_back(i);
      }
    }
    for (i = 0; i < f.size(); i++) {
      c[f[i] + 1]++;
    }
    f.clear();
  }
  cout << st << "\n";
  return 0;
}
