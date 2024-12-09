#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
const int N = 1e5 + 7;
int l, tr, n, m, sum, mini, maxi, a, b, c, x, y, k, z;
int t[20000], tt[100005], ta[100005], ti[100005];
set<int> vis;
vector<int> v;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> tt[i];
  }
  if (t[0]) {
    if (t[x - 1]) {
      cout << "YES";
    } else {
      for (int i = x; i < n; i++) {
        if (t[i] && tt[i]) {
          mini++;
        }
      }
      if (mini) {
        if (tt[x - 1]) {
          cout << "YES";
        } else {
          cout << "NO";
        }
      } else {
        cout << "NO";
      }
    }
  } else {
    cout << "NO";
  }
}
