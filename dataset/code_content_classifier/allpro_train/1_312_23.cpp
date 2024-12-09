#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    vector<int> arr(n / 2);
    for (int i = 0; i < n / 2; i++) {
      scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int b = 0;
    for (int i = 0; i < n / 2; i++) {
      b += abs(arr[i] - 2 * i - 1);
    }
    int w = 0;
    for (int i = 0; i < n / 2; i++) {
      w += abs(arr[i] - 2 * i - 2);
    }
    printf("%d\n", min(b, w));
  }
  return 0;
}
