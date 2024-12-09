#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], brr[n];
  unordered_map<int, int> temp;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    temp[arr[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> brr[i];
    temp[brr[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (temp.find(arr[i] ^ brr[j]) != temp.end()) ans++;
    }
  }
  if (ans % 2 == 0)
    cout << "Karen";
  else
    cout << "Koyomi";
  return 0;
}
