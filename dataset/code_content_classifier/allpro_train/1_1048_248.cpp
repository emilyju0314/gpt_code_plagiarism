#include <bits/stdc++.h>
using namespace std;
long long fun(long long N, long long i) {
  return ((N / i) * (1 + N - (i - 1))) / 2;
}
int main() {
  long long N;
  cin >> N;
  vector<long long> funList;
  funList.push_back((N * (N + 1)) / 2);
  funList.push_back(1);
  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      funList.push_back(fun(N, i));
      if (N / i != i) {
        funList.push_back(fun(N, N / i));
      }
    }
  }
  sort(funList.begin(), funList.end());
  cout << funList[0];
  for (int i = 1; i < funList.size(); i++) {
    cout << " " << funList[i];
  }
  cout << '\n';
}
