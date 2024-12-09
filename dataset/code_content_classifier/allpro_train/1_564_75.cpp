#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  vector<long long int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  long long int sum1 = accumulate((a).begin(), (a).end(), 0LL);
  long long int sum2 = accumulate((b).begin(), (b).end(), 0LL);
  if (sum1 != sum2) return cout << "NO" << '\n', 0;
  long long int ne = 0;
  vector<pair<long long int, long long int> > ans;
  long long int du;
  long long int p = 0, st;
  for (int i = 0; i < m; i++) {
    long long int sum = 0;
    bool ok = false;
    st = p;
    while (p < n && sum != b[i]) {
      sum += a[p];
      p++;
    }
    if (sum != b[i]) return cout << "NO" << '\n', 0;
    vector<long long int> x;
    for (int j = st; j < p; j++) x.push_back(a[j]);
    long long int mn = *min_element((x).begin(), (x).end());
    long long int mx = *max_element((x).begin(), (x).end());
    if (x.size() == 1) continue;
    if (mn == mx) return cout << "NO" << '\n', 0;
    long long int val;
    bool gl = false, gr = false;
    for (int i = 0; i < x.size(); i++) {
      if (i) {
        if (x[i] == mx && x[i - 1] != mx) {
          val = i;
          gl = true;
          break;
        }
      }
      if (i != x.size() - 1) {
        if (x[i] == mx && x[i + 1] != mx) {
          val = i;
          gr = true;
          break;
        }
      }
    }
    val += st;
    if (gl) {
      du = 0;
      long long int itr = val;
      itr--;
      while (itr >= st) {
        ans.push_back(make_pair(itr - ne + 1, 0));
        du++;
        itr--;
      }
      ne += du;
      itr = val;
      itr++;
      while (itr < p) {
        ans.push_back(make_pair(itr - ne + 1, 1));
        ne++;
        itr++;
      }
    } else {
      long long int itr = val;
      itr++;
      long long int du = ne;
      while (itr < p) {
        ans.push_back(make_pair(itr - ne + 1, 1));
        ne++;
        itr++;
      }
      swap(ne, du);
      du -= ne;
      itr = val;
      itr--;
      while (itr >= st) {
        ans.push_back(make_pair(itr - ne + 1, 0));
        du++;
        itr--;
      }
      ne += du;
    }
  }
  cout << "YES" << '\n';
  for (auto x : ans) {
    if (x.second)
      cout << x.first - 1 << " R" << '\n';
    else
      cout << x.first + 1 << " L" << '\n';
  }
}
