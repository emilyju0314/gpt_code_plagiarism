#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> m(5);
  for(int i=0;i<5;i++)
    cin >> m.at(i);
  
  int k=10;
  
  for(int i=0;i<5;i++)
    k=min(k,(m.at(i)-1)%10);
  
  int l=0;
  
  for(int i=0;i<5;i++)
    l+=(m.at(i)-1)/10+1;
  
  cout << (l-1)*10+k+1 << endl;
}