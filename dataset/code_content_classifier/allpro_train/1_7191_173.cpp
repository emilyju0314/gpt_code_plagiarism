#include <bits/stdc++.h>
using namespace std;
vector<long long> sav;
int fr[200007];
bool cmp(int a, int b) { return fr[a] > fr[b]; }
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int arr[n];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (fr[arr[i]] == 0) {
      v.push_back(arr[i]);
    }
    fr[arr[i]]++;
  }
  sort(v.begin(), v.end(), cmp);
  vector<int> res, tem;
  int lo = 1;
  int hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int l = 0;
    for (int i = 0; i < v.size(); i++) {
      int tm = fr[v[i]];
      while (fr[v[i]] >= mid) {
        l++;
        tem.push_back(v[i]);
        fr[v[i]] -= mid;
        if (l == k) break;
      }
      fr[v[i]] = tm;
      if (l == k) break;
    }
    if (l == k) {
      res = tem;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
    tem.clear();
  }
  for (int i = 0; i < k; i++) cout << res[i] << " ";
}
