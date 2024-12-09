#include <iostream>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int p = 0;
  int cnt = p <= x;
  while (n--) {
    int tmp;
    cin >> tmp;
    p += tmp;
    cnt += p <= x;
  }
  cout << cnt << endl;
}