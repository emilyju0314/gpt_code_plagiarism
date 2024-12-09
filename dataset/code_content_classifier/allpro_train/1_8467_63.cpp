#include <bits/stdc++.h>
using namespace std;
int main(){
  int a_1,a_2,a_3;
  cin>>a_1>>a_2>>a_3;
  cout<<max(a_1,max(a_2,a_3))-min(a_1,min(a_2,a_3))<<endl;
}
