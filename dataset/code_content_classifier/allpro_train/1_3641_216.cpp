#include <bits/stdc++.h>
using namespace std;
long long w, h, k;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> w >> h >> k;
  cout << 2 * k * (w + h - 4 * k + 2);
}
