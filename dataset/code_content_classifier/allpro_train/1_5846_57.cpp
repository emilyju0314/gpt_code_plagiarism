#include <bits/stdc++.h>
char a[200001], c;
int i;
int main() {
  for (gets(a), i = 1; a[i]; ++i)
    if (a[i] == a[i - 1])
      for (a[i] = 97; a[i] == a[i - 1] || a[i] == a[i + 1]; ++a[i])
        ;
  puts(a);
}
