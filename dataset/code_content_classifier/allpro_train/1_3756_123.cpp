#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  for (int i = k + 1; i >= 1; i--) cout << i << " ";
  for (int i = k + 2; i <= n; i++) cout << i << " ";
  return 0;
}
