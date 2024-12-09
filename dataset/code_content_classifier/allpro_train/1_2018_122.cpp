#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
int main() {
  int n, arr[N];
  char f;
  char ch[N];
  scanf("%d", &n);
  cin >> ch;
  n = 2 * n;
  for (int i = 0; i < n; i++) arr[i] = ch[i] - '0';
  sort(arr, arr + n / 2);
  sort(arr + n / 2, arr + n);
  bool a = false, b = false;
  for (int i = 0; i < n / 2; i++) {
    if (arr[i] >= arr[n / 2 + i]) a = true;
    if (arr[i] <= arr[n / 2 + i]) b = true;
  }
  if (a && b)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
