#include <bits/stdc++.h>
int main() {
  char a[3];
  scanf("%s", a);
  int l = strlen(a);
  if (l == 1) {
    if (a[0] == '0') printf("zero");
    if (a[0] == '1') printf("one");
    if (a[0] == '2') printf("two");
    if (a[0] == '3') printf("three");
    if (a[0] == '4') printf("four");
    if (a[0] == '5') printf("five");
    if (a[0] == '6') printf("six");
    if (a[0] == '7') printf("seven");
    if (a[0] == '8') printf("eight");
    if (a[0] == '9') printf("nine");
  }
  if (l == 2) {
    if (a[0] == '1' && a[1] == '0')
      printf("ten");
    else if (a[0] == '1' && a[1] == '1')
      printf("eleven");
    else if (a[0] == '1' && a[1] == '2')
      printf("twelve");
    else if (a[0] == '1' && a[1] == '3')
      printf("thirteen");
    else if (a[0] == '1' && a[1] == '4')
      printf("fourteen");
    else if (a[0] == '1' && a[1] == '5')
      printf("fifteen");
    else if (a[0] == '1' && a[1] == '6')
      printf("sixteen");
    else if (a[0] == '1' && a[1] == '7')
      printf("seventeen");
    else if (a[0] == '1' && a[1] == '8')
      printf("eighteen");
    else if (a[0] == '1' && a[1] == '9')
      printf("nineteen");
    else if (a[0] == '2' && a[1] == '0')
      printf("twenty");
    else {
      if (a[0] == '2') printf("twenty");
      if (a[0] == '3') printf("thirty");
      if (a[0] == '4') printf("forty");
      if (a[0] == '5') printf("fifty");
      if (a[0] == '6') printf("sixty");
      if (a[0] == '7') printf("seventy");
      if (a[0] == '8') printf("eighty");
      if (a[0] == '9') printf("ninety");
      if (a[1] == '1') printf("-one");
      if (a[1] == '2') printf("-two");
      if (a[1] == '3') printf("-three");
      if (a[1] == '4') printf("-four");
      if (a[1] == '5') printf("-five");
      if (a[1] == '6') printf("-six");
      if (a[1] == '7') printf("-seven");
      if (a[1] == '8') printf("-eight");
      if (a[1] == '9') printf("-nine");
    }
  }
  return 0;
}
