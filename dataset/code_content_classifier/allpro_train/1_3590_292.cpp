#include <bits/stdc++.h>
using namespace std;
int binarySearch(int* arr, int start, int end, int x) {
  if (start > end) {
    return -1;
  }
  int mid = (start + end) / 2;
  if (arr[mid] >= x && (mid == 0 || arr[mid - 1] < x)) return mid;
  if (arr[mid] > x) {
    return binarySearch(arr, start, mid - 1, x);
  }
  if (arr[mid] < x) {
    return binarySearch(arr, mid + 1, end, x);
  }
}
int main() {
  int n;
  cin >> n;
  int* wormsCnt = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> wormsCnt[i];
  }
  for (int i = 1; i < n; i++) {
    wormsCnt[i] += wormsCnt[i - 1];
  }
  int m;
  cin >> m;
  int* juicy = new int[m];
  for (int i = 0; i < m; i++) {
    cin >> juicy[i];
  }
  for (int i = 0; i < m; i++) {
    int x = binarySearch(wormsCnt, 0, n - 1, juicy[i]);
    cout << x + 1 << endl;
  }
}
