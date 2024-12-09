#include <bits/stdc++.h>
time_t waktu = clock();
void gettime() {
  printf("\nTime : %.2lf", (clock() - waktu) / double(CLOCKS_PER_SEC));
}
bool comp(int a, int b) { return (a > b); }
using namespace std;
int main() {
  int n, x, i, j, cek[100005] = {};
  char data1[100005] = {}, data2[100005] = {};
  scanf("%d", &n);
  scanf("%s", &data1);
  x = strlen(data1);
  for (i = 2; i <= n; i++) {
    scanf("%s", &data2);
    for (j = 0; j < x; j++) {
      if (data1[j] == '?' && data2[j] != '?' && cek[j] == 0)
        data1[j] = data2[j];
      else if (data1[j] != '?' && data2[j] != '?' && data1[j] != data2[j] &&
               cek[j] == 0) {
        cek[j] = 1;
        data1[j] = '?';
      }
    }
  }
  for (i = 0; i < x; i++) {
    if (data1[i] == '?' && cek[i] == 0) data1[i] = 'a';
  }
  printf("%s", data1);
  return 0;
}
