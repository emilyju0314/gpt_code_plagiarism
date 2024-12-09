#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int i, j;
  for (i = 1, j = n; i < j; i++, j--) cout << i << " " << j << " ";
  if (i == j) cout << i << "\n";
}
