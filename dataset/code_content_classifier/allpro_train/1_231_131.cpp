#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int ans{-N};
  while (cin >> N) ans += N;
  cout << ans << endl;
}
