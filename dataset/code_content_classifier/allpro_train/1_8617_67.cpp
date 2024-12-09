#include <bits/stdc++.h>
using namespace std;
vector<long long> seg(100001 * 4), dp(100001, 0);
vector<vector<int>> arr(100001, vector<int>(3));
int n;
long long getVolume(long long r, long long h) {
  return ((long long)r * (long long)r) * (long long)h;
}
long long queryMax(int i, int l, int r, int low, int high) {
  if (low > high) return 0;
  if (l >= low && r <= high)
    return seg[i];
  else if (r < low || l > high)
    return 0;
  int mid = (l + r) / 2;
  long long left = queryMax(2 * i + 1, l, mid, low, high),
            right = queryMax(2 * i + 2, mid + 1, r, low, high);
  return max(left, right);
}
void updateMax(int i, int l, int r, int index, double val) {
  if (r < index || l > index)
    return;
  else if (l >= index && r <= index) {
    seg[i] = val;
    return;
  }
  int mid = (l + r) / 2;
  updateMax(2 * i + 1, l, mid, index, val);
  updateMax(2 * i + 2, mid + 1, r, index, val);
  seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
}
bool compare(vector<int> &a, vector<int> &b) {
  long long v1 = (long long)a[0] * (long long)a[0] * (long long)a[1];
  long long v2 = (long long)b[0] * (long long)b[0] * (long long)b[1];
  return v1 < v2;
}
int main() {
  cout << fixed << setprecision(9);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
    arr[i][2] = i;
  }
  sort(arr.begin(), arr.begin() + n, compare);
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n &&
           getVolume(arr[j][0], arr[j][1]) == getVolume(arr[i][0], arr[i][1])) {
      long long vol = getVolume(arr[j][0], arr[j][1]);
      long long curr = queryMax(0, 0, n - 1, 0, arr[j][2] - 1);
      dp[arr[j][2]] = max(dp[arr[j][2]], curr + vol);
      j++;
    }
    for (int k = i; k < j; k++)
      updateMax(0, 0, n - 1, arr[k][2], dp[arr[k][2]]);
    i = j;
  }
  cout << (double)(*max_element(dp.begin(), dp.begin() + n)) * (double)2.0 *
              acos(0.0)
       << endl;
}
