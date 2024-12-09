#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3] = {0};
  string str;
  for (int i = 0; i < 3; i++) {
    cin >> str;
    if (str[1] == '>')
      arr[str[0] - 'A']++;
    else
      arr[str[2] - 'A']++;
  }
  if (arr[0] == 3 || arr[1] == 3 || arr[2] == 3 ||
      (arr[0] == 1 && arr[1] == 1 && arr[2] == 1))
    cout << "Impossible\n";
  else {
    if (arr[0] == 0)
      cout << "A";
    else if (arr[1] == 0)
      cout << "B";
    else if (arr[2] == 0)
      cout << "C";
    if (arr[0] == 1)
      cout << "A";
    else if (arr[1] == 1)
      cout << "B";
    else if (arr[2] == 1)
      cout << "C";
    if (arr[0] == 2)
      cout << "A";
    else if (arr[1] == 2)
      cout << "B";
    else if (arr[2] == 2)
      cout << "C";
  }
  return 0;
}
