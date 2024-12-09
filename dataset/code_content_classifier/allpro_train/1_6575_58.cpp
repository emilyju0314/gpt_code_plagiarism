#include <iostream>
using namespace std;

int cnt(int n) {
  if (n <= 3) {
    return 1;
  }

  return cnt((n + 2) / 3) + 1;
}

int main() {
  int N;
  cin >> N;

  cout << cnt(N) << endl;

  return 0;
}