#include <bits/stdc++.h>
using namespace std;
void f() {
  int n, s, k;
  cin >> n >> s >> k;
  set<int> data;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    data.insert(x);
  }
  auto it = data.find(s);
  if (it == data.end()) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (s - i >= 1 && data.find(s - i) == data.end()) {
      cout << i << "\n";
      return;
    }
    if (s + i <= n && data.find(s + i) == data.end()) {
      cout << i << "\n";
      return;
    }
  }
}
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    f();
  }
  return 0;
}
