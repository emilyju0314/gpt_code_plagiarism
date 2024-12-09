#include <bits/stdc++.h>
using namespace std;
int c[7];
void BubbleSort(int arr[], int l);
int main() {
  int n, i, j;
  cin >> n;
  char a[n][7];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (j = 0; j < 7; j++)
    for (i = 0; i < n; i++) {
      if (a[i][j] == '1') c[j]++;
    }
  BubbleSort(c, 7);
  cout << c[6] << endl;
  return 0;
}
void swapp(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void BubbleSort(int arr[], int l) {
  int i, j, swapped;
  for (j = 0; j < l - 1; j++) {
    swapped = 0;
    for (i = 0; i < l - j - 1; i++) {
      if (arr[i] > arr[i + 1]) swapp(arr + i, arr + i + 1);
      swapped = 1;
    }
    if (swapped == 0) break;
  }
}
