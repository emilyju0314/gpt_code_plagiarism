#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (n == k) {
    cout << -1 << endl;
  } else {
    for (int i = 1; i <= n - k - 1; i++) {
      cout << i + 1 << " ";
    }
    cout << 1 << " ";
    for (int i = n - k + 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
int main() { solve(); }
