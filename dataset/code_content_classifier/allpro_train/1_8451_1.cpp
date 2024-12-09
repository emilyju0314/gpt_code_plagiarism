#include <bits/stdc++.h>
using namespace std;
vector<int> numdig(int num) {
  vector<int> temp;
  for (int i = 0; i < 4; i++) {
    temp.push_back(num % 10);
    num /= 10;
  }
  reverse(temp.begin(), temp.end());
  return temp;
}
pair<int, int> valid(int a, int b) {
  int x = 0, y = 0;
  vector<int> A = numdig(a);
  vector<int> B = numdig(b);
  for (int i = 0; i < 4; i++) {
    if (A[i] == B[i]) {
      x++;
      continue;
    }
    for (int j = 0; j < 4; j++) {
      if (A[i] == B[j]) {
        y++;
      }
    }
  }
  return make_pair(x, y);
}
int main() {
  int queries;
  queries = 1;
  while (queries--) {
    srand(2333333);
    vector<int> possibilities, cutshort;
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        if (j == i) continue;
        for (int k = 0; k <= 9; k++) {
          if (k == j || k == i) continue;
          for (int l = 0; l <= 9; l++) {
            if (l == i || l == j || l == k) continue;
            int num = (1000 * i) + (100 * j) + (10 * k) + l;
            possibilities.push_back(num);
          }
        }
      }
    }
    int tries = 1, flag = 1, x, y;
    while (tries <= 7) {
      random_shuffle(possibilities.begin(), possibilities.end());
      vector<int> dig = numdig(possibilities[0]);
      for (auto it : dig) {
        cout << it;
      }
      fflush(stdout);
      cout << endl;
      cin >> x >> y;
      if (x == 4 && y == 0) {
        break;
      }
      cutshort.clear();
      for (auto it : possibilities) {
        if (make_pair(x, y) == valid(it, possibilities[0]))
          cutshort.push_back(it);
      }
      possibilities = cutshort;
      tries++;
    }
    if (flag == 1) {
      cout << "tries exceeded" << endl;
    }
  }
  return 0;
}
