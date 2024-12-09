#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long sum;
int A[100007];
int T[100007];
multiset<int> S1;
multiset<int> S2;
long long S[100007];
long long Abs(long long x) {
  if (x > 0) return x;
  return -x;
}
void Add(int x) {
  if (x >= 0)
    S2.insert(x);
  else {
    sum += abs(x);
    S1.insert(x);
    while (S1.size() > k) {
      multiset<int>::iterator it;
      it = S1.end();
      it--;
      int t = *it;
      sum -= abs(t);
      S2.insert(t);
      S1.erase(it);
    }
  }
}
void Erase(int x) {
  if (S2.find(x) != S2.end())
    S2.erase(S2.find(x));
  else {
    S1.erase(S1.find(x));
    sum -= abs(x);
    while (S1.size() < k && S2.size() > 0) {
      int t = *S2.begin();
      if (t < 0) {
        S1.insert(t);
        sum += abs(t);
        S2.erase(S2.begin());
      } else
        break;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int(i) = (0); (i) < (n); ++(i)) scanf("%d", &A[i]);
  cin >> k;
  long long res = -1000000000000000000LL;
  S1.clear();
  S2.clear();
  S[0] = A[0];
  for (int(i) = (1); (i) < (n); ++(i)) S[i] = S[i - 1] + A[i];
  sum = 0;
  for (int(i) = (0); (i) < (m); ++(i)) Add(A[i]);
  for (int i = 0; i + m - 1 < n; i++) {
    long long d = S[i + m - 1] - (i == 0 ? 0 : S[i - 1]);
    res = max(res, Abs(d + sum * 2));
    Erase(A[i]);
    if (i + m < n) Add(A[i + m]);
  }
  for (int(i) = (0); (i) < (n); ++(i)) A[i] *= -1;
  S1.clear();
  S2.clear();
  S[0] = A[0];
  for (int(i) = (1); (i) < (n); ++(i)) S[i] = S[i - 1] + A[i];
  sum = 0;
  for (int(i) = (0); (i) < (m); ++(i)) Add(A[i]);
  for (int i = 0; i + m - 1 < n; i++) {
    long long d = S[i + m - 1] - (i == 0 ? 0 : S[i - 1]);
    res = max(res, Abs(d + sum * 2));
    Erase(A[i]);
    if (i + m < n) Add(A[i + m]);
  }
  cout << res << endl;
  return 0;
}
