#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;
int N;
int arr[MAX];
int calc() {
  ll tot = 0;
  int ret = 0;
  for (int i = 1; i <= (N); ++i) {
    if (tot <= arr[i]) {
      tot += arr[i];
      ++ret;
    }
  }
  return ret;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  cin >> N;
  for (int i = 1; i <= (N); ++i) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + N + 1);
  cout << calc() << '\n';
}
