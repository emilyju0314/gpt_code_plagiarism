#include <bits/stdc++.h>
using namespace std;
char temp[int(10E5 + 10)];
int main() {
  int size = 0;
  bool flag = false;
  for (size = 0; scanf(" %c", &temp[size]) != EOF; ++size)
    ;
  int removed = -1;
  for (int i = 0; i < size; ++i) {
    if (temp[i] == '0') {
      removed = i;
      break;
    }
  }
  if (removed == -1) removed = 0;
  for (int i = 0; i < size; ++i) {
    if (i != removed && (temp[i] == '0' || temp[i] == '1')) {
      printf("%c", temp[i]);
    }
  }
  printf("\n");
  return 0;
}
