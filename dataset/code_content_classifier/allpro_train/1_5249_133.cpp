#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 4, INF = 2e18;
long long n, k;
string g = "YES", h = "NO";
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  if (n / k % 2 == 1)
    cout << g;
  else
    cout << h;
}
