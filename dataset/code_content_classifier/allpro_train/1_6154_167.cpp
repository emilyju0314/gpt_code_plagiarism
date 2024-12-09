#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  if (n % 2 == 1)
    cout << "0";
  else {
    n /= 2;
    long int otv = pow(2, n);
    cout << otv;
  }
  return 0;
}
