#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << "I hate ";
  if (a != 1) {
    cout << "that ";
  }
  for (int i = 1; i < a; i++) {
    if (i % 2 == 0) {
      cout << "I hate ";
    }
    if (i % 2 == 1) {
      cout << "I love ";
    }
    if (i != a - 1) {
      cout << "that ";
    }
  }
  cout << "it";
}
