#include <bits/stdc++.h>
using namespace std;

int main(){
int a[5],k;
cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> k;
(a[4] - a[0] > k)? cout << ":(\n" : cout << "Yay!\n";
  return 0;
}
