#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int gcd(int a, int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
bool compare(long long i, long long j) { return i > j; }
long long solution(const vector<int>& A, int k) {
  const int N = A.size();
  if (k == 0) {
    return 1;
  }
  if (k == 1) {
    set<int> st;
    for (int x : A) {
      st.insert(x);
    }
    return st.size();
  }
  if (N < k || N < 1 || k < 1) return 0;
  if (N == k) return 1;
  vector<long long> v1(256, 0);
  vector<long long> v2(256, 0);
  vector<long long> v3(256, 0);
  v2[N - 1] = 1;
  v3[A[N - 1] - 1] = 1;
  for (int i = N - 2; i >= 0; i--) {
    v2[i] = v2[i + 1];
    if (v3[A[i] - 1] == 0) {
      v2[i]++;
      v3[A[i] - 1] = 1;
    }
  }
  for (int j = 1; j < k; j++) {
    fill(v3.begin(), v3.end(), 0);
    v1[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
      v1[i] = v1[i + 1];
      v1[i] = v1[i] + v2[i + 1];
      v1[i] = v1[i] - v3[A[i] - 1];
      v3[A[i] - 1] = v2[i + 1];
    }
    v2 = v1;
  }
  return v1[0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string temp;
  cin >> temp;
  vector<int> A;
  for (int i = 0; i < temp.size(); i++) {
    A.push_back(temp[i]);
  }
  int x, ans = 0, count = 0;
  for (int i = n; i >= 0; i--) {
    x = solution(A, i);
    count += x;
    ans += x * (n - i);
    if (count >= k) {
      ans -= (count - k) * (n - i);
      count = k;
      break;
    }
  }
  if (count != k) {
    cout << "-1" << endl;
  } else
    cout << ans << endl;
}
