#include <bits/stdc++.h>
using namespace std;
long long input[100000], n, output, table[100000], a, tlg, go, high, lg;
int main(int argc, char** argv) {
  int i, j, k;
  while (scanf(" %d", &n) == 1) {
    output = 0;
    lg = 1;
    tlg = 1;
    scanf(" %d", &input[0]);
    for (i = 1; i < n; i++) {
      scanf(" %d", &a);
      if (a != input[lg - 1]) {
        input[lg] = a;
        lg++;
      }
    }
    table[0] = input[0];
    input[lg] = 1000000000;
    for (i = 1; i < lg; i++) {
      if ((input[i] < input[i - 1] && input[i] < input[i + 1]) ||
          (input[i] > input[i - 1] && input[i] > input[i + 1])) {
        table[tlg] = input[i];
        tlg++;
      }
    }
    table[tlg] = 1000000000;
    high = table[0];
    for (i = 0; i < tlg; i++) {
      if (table[i] > table[i + 1] && table[i + 1] < table[i + 2]) {
        if (high > table[i + 2]) {
          output += table[i + 2] - table[i + 1];
          i++;
        } else {
          output += high - table[i + 1];
          high = table[i + 2];
          i++;
        }
      } else {
        high = table[i + 1];
      }
    }
    cout << output << endl;
  }
  return 0;
}
