#include <bits/stdc++.h>
using namespace std;
long long int recpow(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return recpow((x * x) % 1000000007, n / 2);
  else
    return (x * recpow((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
}
bool sortbysec(
    const pair<pair<long long int, long long int>, long long int> &a,
    const pair<pair<long long int, long long int>, long long int> &b) {
  if (a.second == b.second)
    return (a.first.second < b.first.second);
  else
    return (a.second > b.second);
}
string rev(string s) {
  string t;
  for (long long int i = s.length() - 1; i >= 0; i--) {
    t.push_back(s[i]);
  }
  return t;
}
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
string oh(string s, long long int n, long long int k) {
  long long int r = 1;
  string ans = "";
  for (long long int i = 0; i < n; i += k) {
    long long int j = i + 1;
    while (j < i + k and s[j] == s[j - 1]) j++;
    if (j < i + k) {
      r = 0;
      break;
    }
  }
  if (r == 1) {
    for (long long int i = 0; i < n; i += k) ans.push_back(s[i]);
  } else
    ans = "0";
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    long long int k = 0;
    while (1) {
      if (n - pow(2, k + 1) + 1 >= pow(2, k) and
          n - pow(2, k + 1) + 1 < pow(2, k + 2)) {
        break;
      }
      k++;
    }
    long long int x = n - pow(2, k + 1) + 1;
    long long int a = -1, b = -1;
    if (x > pow(2, k + 1)) {
      a = x / 2;
      b = x - a;
    } else
      a = x;
    for (long long int i = 0; i < k; i++) {
      v.push_back(pow(2, i));
    }
    if (b == -1)
      v.push_back(a - pow(2, k));
    else {
      v.push_back(a - pow(2, k));
      v.push_back(b - a);
    }
    cout << v.size() << "\n";
    for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
  }
  return 0;
}
