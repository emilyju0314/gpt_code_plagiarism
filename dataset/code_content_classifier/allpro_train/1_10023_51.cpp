#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n;
cin >> n;
long long b = 0;
for(int i = 1;i<n+1;i++){
if(i % 3 != 0 && i % 5 != 0)b+=i;}
cout << b << endl;}