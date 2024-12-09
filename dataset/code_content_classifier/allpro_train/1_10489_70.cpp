#include <bits/stdc++.h>
using namespace std;
int makeUnique(int *arr, int n) {
  int cnt = 0, u, v;
  for (int i = 0; i < n - 1; i++)
    if (arr[i] == arr[i + 1]) {
      cnt++;
      if (arr[i] == 0 || cnt > 1) return 2;
      if (i == 0 || arr[i - 1] + 1 != arr[i])
        arr[i]--;
      else
        return 2;
    }
  return cnt;
}
bool solve(int *arr, int n) {
  int diff = 0;
  for (int i = 0; i < n; i++) diff += arr[i] - i;
  return diff % 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int x = makeUnique(arr, n);
  if (x != 2 && x ^ solve(arr, n))
    cout << "sjfnb" << endl;
  else
    cout << "cslnb" << endl;
  return 0;
}
