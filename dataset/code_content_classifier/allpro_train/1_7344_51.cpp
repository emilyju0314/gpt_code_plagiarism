#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  double mountain[1111],ans;
  int i=0;
  while(cin >> mountain[i]){
    i++;
  }
  sort(mountain,mountain+i);
  ans = mountain[i-1] - mountain[0];
  cout << ans << endl;
}