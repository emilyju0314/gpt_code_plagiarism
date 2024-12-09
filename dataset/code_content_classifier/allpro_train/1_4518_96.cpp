#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  string input;
  cin >> t;
  while (t--) {
    cin >> input;
    cout << input.size() - count(input.begin(), input.end(), '0') << endl;
    for (int i = input.size() - 1; i >= 0; i--) {
      if (input[i] != '0') {
        cout << input[i] + string(input.size() - i - 1, '0') + " ";
      }
    }
    cout << endl;
  }
  return 0;
}
