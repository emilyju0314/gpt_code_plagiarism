#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
int main() {
  int i, j, k;
  long long N, K;
  cin >> N >> K;
  deque<long long> vec;
  long long sum = 0;
  for (i = 0; i < N; i++) {
    cin >> k;
    vec.push_back(k);
    sum += k;
  }
  if (sum < K) {
    cout << -1 << endl;
    return 0;
  } else if (sum == K) {
    cout << endl;
    return 0;
  }
  long long b = 0, e = 1000100100;
  while (b + 1 < e) {
    long long med = (b + e) / 2LL;
    long long tot = 0;
    for (i = 0; i < vec.size(); i++) tot += min(med, vec[i]);
    if (tot <= K)
      b = med;
    else
      e = med;
  }
  for (i = 0; i < vec.size(); i++)
    K -= min(b, vec[i]), vec[i] -= min(b, vec[i]);
  int ind = 0;
  while (K > 0) {
    if (vec[0] > 0) {
      K--;
      vec[0]--;
    }
    ind = (ind + 1) % (int)vec.size();
    int a = vec[0];
    vec.pop_front();
    vec.push_back(a);
  }
  int first = 1;
  for (i = 0; i < vec.size(); i++) {
    if (vec[i]) {
      if (first)
        first = 0;
      else
        cout << " ";
      cout << ind + 1;
    }
    ind = (ind + 1) % (int)vec.size();
  }
  cout << endl;
  return 0;
}
