#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[50];
  gets(s);
  int i, count = 0;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '1' || s[i] == '3' || s[i] == '5' ||
        s[i] == '7' || s[i] == '9')
      count++;
  }
  std::cout << count;
  return 0;
}
