#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int b;
  cin >> b;
  long long int c = 0;
  for (int i = 2; i <= sqrt(b); i++) {
    if (b % i == 0) {
      if (i == b / i)
        c++;
      else
        c = c + 2;
    }
  }
  if (b == 1)
    cout << (c + 1);
  else
    cout << c + 2;
}
