#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, ans;
  vector<int> A;

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  ans = 0;
  for(int i = 0; i < M; i++) {
    if(A[i] > M)
      ans++;
  }
  cout << ans << endl;

  return 0;
}

