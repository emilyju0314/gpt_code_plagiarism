#include <bits/stdc++.h>
using namespace std;
void ins(long long int a[], long long int n, long long int i = 0) {
  for (long long int i = 0; i < n; i++) a[i] = i;
}
template <typename t>
void ins(t a[], long long int n, t b = 0) {
  for (long long int i = 0; i < n; i++) a[i] = b;
}
void print(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  ;
  cout << endl;
}
template <typename t>
void print(t a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  ;
  cout << endl;
}
void po(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
template <typename t>
void po(t a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
long long int visited[100009];
vector<long long int> a[100009];
long long int n;
long long int b[100009];
long long int c[100001];
void start() {
  cin >> n;
  for (long long int i = 0; i < n - 1; i++) {
    cin >> b[i + 1];
    a[i + 2].push_back(b[i + 1]);
    a[b[i + 1]].push_back(i + 2);
  }
  for (long long int i = 0; i < n + 3; i++) {
    visited[i] = 0;
    c[i] = 0;
  }
}
void dfs(long long int s, long long int t) {
  visited[s] = 1;
  if (s != 1)
    c[t + 1] += a[s].size() - 1;
  else
    c[t + 1] += a[s].size();
  for (long long int i = 0; i < a[s].size(); i++) {
    if (!visited[a[s][i]]) dfs(a[s][i], t + 1);
  }
}
int main() {
  start();
  long long int count = 0;
  dfs(1, 0);
  for (long long int i = 0; i < n + 3; i++) {
    if (c[i] % 2 == 1) {
      count++;
    }
  }
  cout << count + 1 << endl;
  return 0;
}
