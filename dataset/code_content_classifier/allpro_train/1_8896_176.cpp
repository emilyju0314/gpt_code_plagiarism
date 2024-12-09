#include <iostream>

using namespace std;

int main() {
  string N;
  cin >> N;

  int count = 0;

  for (char i : N) if (i == '2') count++;

  cout << count << endl;
}