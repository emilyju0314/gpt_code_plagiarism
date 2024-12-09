#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  cin >> k;
  char a[] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
  char b[] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
  char c[] = "|#.......................|";
  char d[] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
  i = 0;
  j = 1;
  while (i < k) {
    a[j] = 'O';
    i++;
    if (i == k) break;
    b[j] = 'O';
    i++;
    if (i == k) break;
    if (j == 1) {
      c[j] = 'O';
      i++;
      if (i == k) break;
    }
    d[j] = 'O';
    i++;
    j += 2;
  }
  cout << "+------------------------+\n";
  cout << a << endl << b << endl << c << endl << d << endl;
  cout << "+------------------------+\n";
  return 0;
}
