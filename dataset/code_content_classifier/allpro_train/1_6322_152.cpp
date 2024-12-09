#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long int diff = arr[n - 1] - arr[0] + 1;
  cout << diff - n << endl;
}
