#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
inline void amax(T& a, const T& b) {
  if (a < b) a = b;
}
template <class T>
inline void rv(vector<T>& v, int n) {
  vector<T>(n).swap(v);
  for (int i = 0; i < (n); i++) cin >> v[i];
}
inline void rv(int* v, int n) {
  for (int i = 0; i < (n); i++) scanf("%d", &v[i]);
}
inline void rv(long long* v, int n) {
  for (int i = 0; i < (n); i++) scanf("%lld", &v[i]);
}
inline vector<int> rvi(int n) {
  vector<int> v(n);
  for (int i = 0; i < (n); i++) scanf("%d", &v[i]);
  return v;
}
inline vector<long long> rvl(int n) {
  vector<long long> v(n);
  for (int i = 0; i < (n); i++) scanf("%lld", &v[i]);
  return v;
}
inline vector<string> rvs(int n) {
  vector<string> v(n);
  for (int i = 0; i < (n); i++) scanf("%s", &v[i]);
  return v;
}
template <class T>
inline void readvv(vector<vector<T>>& v, int m, int n) {
  vector<vector<T>>(m).swap(v);
  for (int i = 0; i < (m); i++) readv(v[i], n);
}
inline void pvi(vector<int>& v) {
  for (int i = 0; i < (v.size()); i++) printf("%d ", v[i]);
  printf("\n");
}
inline void pvl(vector<long long>& v) {
  for (int i = 0; i < (v.size()); i++) {
    printf("%lld ", v[i]);
  }
  printf("\n");
}
inline void pvs(vector<string>& v) {
  for (int i = 0; i < (v.size()); i++) {
    printf("%s\n", v[i].c_str());
  }
}
int main() {
  long long n, u, v, s;
  scanf("%lld %lld", &n, &s);
  vector<long long> g(n);
  for (int i = 0; i < (n - 1); i++) {
    scanf("%lld %lld", &u, &v);
    g[u - 1]++;
    g[v - 1]++;
  }
  double leaves = 0, two = 2;
  for (int i = 0; i < (n); i++) {
    if (g[i] == 1) leaves++;
  }
  cout << setprecision(30) << endl;
  printf("%.30f\n", ((two * s) / leaves));
  return 0;
}
