#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  int count = 0;
  while(1){
      string b;
      cin >> b;
      if(b == "END_OF_TEXT")break;
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    if(b == a)count++;
  }
  cout << count << endl;
}
