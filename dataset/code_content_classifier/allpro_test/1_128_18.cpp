#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int moguciprosti[9] = {3, 5, 7, 11, 13, 17, 19, 23, 29};
  for (int testcase = 0; testcase < t; testcase++) {
    int n;
    cin >> n;
    if (n % 2 == 0)
      cout << "2 " << n - 3 << " 1" << endl;
    else {
      for (int i = 0; i < 9; i++) {
        if ((n - 1) % moguciprosti[i] != 0) {
          cout << moguciprosti[i] << " " << n - moguciprosti[i] - 1 << " " << 1
               << endl;
          break;
        }
      }
    }
  }
  return 0;
}
