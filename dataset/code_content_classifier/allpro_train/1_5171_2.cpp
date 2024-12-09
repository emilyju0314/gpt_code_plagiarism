#include<bits/stdc++.h>
using namespace std;
int main(){
long A, B;
cin >> A >> B;
long i = 1;
  while(A * i % B != 0) i++;
  cout << A * i << endl;
}