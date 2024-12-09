#include <bits/stdc++.h>
using namespace std;
void Erase(long long l, long long& ans, long long arr[], long long n) {
  if (l <= 0 || l >= n + 1) return;
  if (arr[l - 1] < arr[l] && arr[l] > arr[l + 1]) ans -= arr[l];
  if (arr[l - 1] > arr[l] && arr[l] < arr[l + 1]) ans += arr[l];
}
void Set(long long l, long long& ans, long long arr[], long long n) {
  if (l <= 0 || l >= n + 1) return;
  if (arr[l - 1] < arr[l] && arr[l] > arr[l + 1]) ans += arr[l];
  if (arr[l - 1] > arr[l] && arr[l] < arr[l + 1]) ans -= arr[l];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, q, ans = 0;
    cin >> n >> q;
    long long* arr = new long long[n + 3];
    arr[0] = INT_MIN;
    arr[n + 1] = INT_MIN;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (long long i = 1; i <= n; i++) {
      if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ans += arr[i];
      if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) ans -= arr[i];
    }
    cout << ans << "\n";
    while (q--) {
      long long l, r;
      cin >> l >> r;
      if ((l >= 1 && l <= n) && (r >= 1 && r <= n)) {
        set<long long> st;
        st.insert(l - 1);
        st.insert(l);
        st.insert(l + 1);
        st.insert(r - 1);
        st.insert(r);
        st.insert(r + 1);
        for (auto i : st) Erase(i, ans, arr, n);
        swap(arr[l], arr[r]);
        for (auto i : st) Set(i, ans, arr, n);
      }
      cout << ans << "\n";
    }
  }
}
