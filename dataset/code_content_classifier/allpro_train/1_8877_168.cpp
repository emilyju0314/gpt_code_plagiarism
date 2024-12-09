#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, temp;
  cin >> n;
  if (n % 7 == 6)
    cout << (n / 7) * 2 + 1 << " ";
  else
    cout << (n / 7) * 2 << " ";
  if (n % 7 >= 2)
    cout << (n / 7) * 2 + 2 << endl;
  else
    cout << (n / 7) * 2 + (n % 7) << endl;
  return 0;
}
