#include <bits/stdc++.h>
template <class C, class E>
inline bool contains(const C& container, const E& element) {
  return container.find(element) != container.end();
}
template <class T>
inline void checkmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T& a, T b) {
  if (b > a) a = b;
}
using namespace std;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << std::setprecision(15);
  cout << std::fixed;
  unsigned long long n, k;
  cin >> n >> k;
  unsigned long long res = k / n;
  if (k % n != 0) res++;
  cout << res;
  return 0;
}
