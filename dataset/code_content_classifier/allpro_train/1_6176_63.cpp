#include <bits/stdc++.h>
using namespace std;
int gInt() {
  int i;
  scanf("%d", &i);
  return i;
}
long long int gLong() {
  long long int i;
  scanf("%lld", &i);
  return i;
}
double gDouble() {
  double i;
  scanf("%lf", &i);
  return i;
}
void quit() {
  fflush(stdout);
  exit(0);
}
char stra[100005];
char strb[100005];
int lena, lenb;
int main(int argc, char** argv) {
  scanf("%s %s", stra, strb);
  lena = strlen(stra);
  lenb = strlen(strb);
  int para = 0, parb = 0;
  for (int i = 0; i < lena; i++) para += stra[i] - '0';
  for (int i = 0; i < lenb; i++) parb += strb[i] - '0';
  para = ((para + 1) / 2) * 2;
  if (para >= parb)
    printf("YES\n");
  else
    printf("NO\n");
  quit();
}
