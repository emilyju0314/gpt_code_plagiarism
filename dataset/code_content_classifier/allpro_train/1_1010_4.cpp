#include <bits/stdc++.h>
using namespace std;
long long n;
long long letter[1100];
long long arr[100];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if (n == 0) {
    cout << "a"
         << "\n";
    return 0;
  }
  letter[2] = 1;
  for (int i = 3; i <= 1000; i++) {
    letter[i] = (i - 1) + letter[i - 1];
  }
  for (int i = 0; i < 26 and n; i++) {
    long long _count = 0;
    for (int j = 2; j <= 1000; j++) {
      if (letter[j] <= n) {
        _count = j;
      } else
        break;
    }
    arr[i] = _count;
    n -= letter[_count];
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < arr[i]; j++) cout << (char)(i + 'a');
  }
  cout << "\n";
}
