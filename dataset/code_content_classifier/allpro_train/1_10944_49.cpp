#include <bits/stdc++.h>
using namespace std;
queue<long long> q;
struct classcomp {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  }
};
set<pair<long long, long long>, classcomp> st;
long long arr[200005], sum[200005];
int main() {
  int n, k, i, j;
  cin >> n >> k;
  for (i = 1; i < n + 1; i++) {
    cin >> arr[i];
    sum[i] = arr[i] + sum[i - 1];
  }
  long long sm = 0;
  i = n;
  for (j = 0; j < k; j++) {
    q.push(arr[i]);
    sm += arr[i];
    i--;
  }
  st.insert(make_pair(sm, i + 1));
  long long mx = -1, ansb, ansa;
  while (i >= k) {
    pair<long long, long long> top = *st.rbegin();
    long long temp = sum[i] - sum[i - k] + top.first;
    if (temp > mx) {
      ansb = top.second;
      ansa = i - k;
      mx = temp;
    } else if (temp == mx) {
      if (ansa > i - k) {
        ansa = i - k;
        ansb = top.second;
      } else if (ansa == i - k) {
        ansb = min(ansb, top.second);
      }
    }
    sm -= q.front();
    sm += arr[i];
    q.pop();
    q.push(arr[i]);
    st.insert(make_pair(sm, i));
    i--;
  }
  cout << ansa + 1 << " " << ansb;
  return 0;
}
