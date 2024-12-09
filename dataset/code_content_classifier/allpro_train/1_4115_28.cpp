#include <bits/stdc++.h>
using namespace std;
char a[1000001], b[1000001];
char c[1000001], d[1000001];
int main() {
  cin >> a >> b;
  long long int l1, l2, i, j, k;
  l1 = strlen(a);
  l2 = strlen(b);
  if (a[0] == '0') {
    for (i = 0; i < l1; i++) {
      if (a[i] != '0') {
        j = i;
        break;
      }
    }
    if (j == 0) {
      c[0] = 0;
    } else {
      for (i = j, k = 0; i < l1; i++) {
        c[k++] = a[i];
      }
    }
  } else {
    for (i = 0, k = 0; i < l1; i++) {
      c[k++] = a[i];
    }
  }
  if (b[0] == '0') {
    j = 0;
    for (i = 0; i < l2; i++) {
      if (b[i] > '0') {
        j = i;
        break;
      }
    }
    if (j == 0) {
      d[0] = 0;
    } else {
      for (i = j, k = 0; i < l2; i++) {
        d[k++] = b[i];
      }
    }
  } else {
    for (i = 0, k = 0; i < l2; i++) {
      d[k++] = b[i];
    }
  }
  long long int l3, l4, ck = 0;
  l3 = strlen(c);
  l4 = strlen(d);
  if (l3 == l4) {
    for (i = 0; i < l3; i++) {
      if (c[i] == d[i]) {
        ck++;
        continue;
      }
      if (c[i] > d[i]) {
        cout << ">" << endl;
        break;
      }
      if (c[i] < d[i]) {
        cout << "<" << endl;
        break;
      }
    }
    if (ck == l3) {
      cout << "=" << endl;
    }
  } else {
    if (l3 > l4) {
      cout << ">" << endl;
    }
    if (l3 < l4) {
      cout << "<" << endl;
    }
  }
  return 0;
}
