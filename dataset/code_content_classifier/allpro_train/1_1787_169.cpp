#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n = 0, ct = 0, x = 0, ct2 = 0;
  cin >> n;
  long long int arr[n + 1];
  for (int a = 0; a < n; a++) cin >> arr[a];
  bool ok = false;
  arr[n] = -1000000000000000000;
  for (int a = 0; a < n; a++)
    if (arr[a] == arr[a + 1])
      ct++;
    else {
      ct++;
      ct2 += (ct * (ct + 1)) / 2;
      ct = 0;
    }
  cout << ct2;
}
