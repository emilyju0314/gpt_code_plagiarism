#include <bits/stdc++.h>
using namespace std;
void print(long long int *arr, long long int k, long long int l) {
  for (int i = l; i < k; i++) cout << arr[i] << " ";
  cout << endl;
}
int main() {
  int n, c;
  cin >> n;
  c = floor(sqrt(n));
  for (int i = 1; i <= n / c + 1; i++) {
    for (int j = 0; j < c; j++) {
      if (n - c * i + 1 + j < 1) continue;
      cout << n - c * i + 1 + j << " ";
    }
  }
  cout << endl;
}
