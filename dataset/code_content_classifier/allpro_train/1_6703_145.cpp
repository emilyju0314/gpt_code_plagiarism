#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  cout << arr[n - k];
  return 0;
}
