#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int rubles, dollar, euro;
  cin >> rubles >> dollar >> euro;
  long long int left = rubles;
  for (long long int i = 0; i * 5 * euro <= rubles; i++) {
    left = min(left, (rubles - i * 5 * euro) % dollar);
  }
  cout << left;
}
