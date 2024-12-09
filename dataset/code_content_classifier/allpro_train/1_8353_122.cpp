#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int main() {
  int N, M, Answer = 0;
  cin >> N >> M;
  vector<int> data(N);
  for (int i = 0; i < N; ++i) {
    cin >> data[i];
  }
  int count = 0;
  for (int i = 0; i < N; ++i) {
    if (data[i] > count) {
      Answer++;
      count = M;
    }
    count -= data[i];
  }
  cout << Answer << endl;
  return 0;
}
