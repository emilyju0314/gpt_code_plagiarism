#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vp;
vector<int> v;
int arr[100];
const int N = 1e3 + 74, M = 1e6 + 74, OO = 0x3f3f3f3f, P = 1e5 + 5;
void g4(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int main() {
  g4();
  int n, ar[P], arr[P], a, b;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i] >> arr[i];
  }
  a = *min_element(ar + 1, ar + (n + 1));
  b = *max_element(arr + 1, arr + (n + 1));
  for (int i = 1; i <= n; ++i) {
    if (ar[i] <= a && arr[i] >= b) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
