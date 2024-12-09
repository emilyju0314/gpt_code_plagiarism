#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x;
  cin >> n >> x;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  unsigned long long int cont = 0;
  long long int j = 0;
  while (x > 1 && j < n) {
    cont += arr[j] * x;
    x--;
    j++;
  }
  while (j < n) {
    cont += arr[j];
    j++;
  }
  cout << cont;
  return 0;
}
